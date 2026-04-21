#include <stddef.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  size_t len;
  size_t capacity;
  size_t elem_size;
} Dyn_Arr_Header;
#define DynArrayHeader(ptr) ((Dyn_Arr_Header *)(ptr) - 1)
#define DynArrayLen(ptr) DynArrayHeader(ptr)->len
#define DynArrayTry(statment)                                                  \
  if (!statment)                                                               \
    return 0;

// return null if allocation fails
static inline void *dyn_array_init(size_t elem_size, size_t cap) {
  Dyn_Arr_Header *header =
      (Dyn_Arr_Header *)malloc(sizeof(Dyn_Arr_Header) + (elem_size * cap));
  DynArrayTry(header);
  header->len = 0;
  header->capacity = cap;
  header->elem_size = elem_size;

  return header + 1;
}
static inline void dyn_array_deinit(void *ptr) {
  return free(DynArrayHeader(ptr));
}
// return 1 on success 0 on failure
static inline int dyn_array_append(void **ptr, void *arr, size_t len) {
  Dyn_Arr_Header *header = DynArrayHeader(*ptr);

  size_t needed = header->len + len;
  if (needed > header->capacity) {
    size_t new_cap = header->capacity ? header->capacity : 1;
    while (new_cap < needed)
      new_cap *= 2;

    void *new_arr = dyn_array_init(header->elem_size, new_cap);
    DynArrayTry(new_arr);
    memcpy(new_arr, *ptr, header->elem_size * header->len);
    DynArrayHeader(new_arr)->len += header->len;
    dyn_array_deinit(*ptr);

    *ptr = new_arr;
    header = DynArrayHeader(*ptr);
  }
  void *dest = (char *)(*ptr) + (header->elem_size * header->len);
  memcpy(dest, arr, header->elem_size * len);
  header->len += len;
  return 1;
}
// return 1 on success 0 on failure
static inline int dyn_array_push(void **ptr, void *data) {
  return dyn_array_append(ptr, data, 1);
}
// return a pointer to popped data cannot gurantee liftime of popped value, returns null on len 0
static inline void *dyn_array_pop(void *ptr) {
  Dyn_Arr_Header *header = DynArrayHeader(ptr);
  if (header->len == 0) return NULL;
  void *value = (char *)ptr + (header->elem_size * (header->len - 1));
  header->len -= 1;
  return value;
}
static inline size_t dyn_array_len(void *ptr) { return DynArrayLen(ptr); }
