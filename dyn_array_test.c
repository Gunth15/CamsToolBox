#include "dyn_array.h"
#include <assert.h>
#include <stdio.h>

#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define RED "\033[31m"

int main() {
  int *arr = dyn_array_init(sizeof(int), 6);

  //  Fill array
  for (int i = 0; i < 100; ++i) {
    dyn_array_push((void **)&arr, &i);
    printf("Pushed %d to array\n", i);
  }
  printf("len before pop: %zu\n", dyn_array_len(arr));
  for (int i = 99; i >= 0; --i) {
    int *d = dyn_array_pop(arr);
    printf("The output of the array is %d\n", *d);
    assert(i == *d && "Not expected output");
  }

  dyn_array_deinit(arr);
  arr = dyn_array_init(sizeof(int), 6);

  for (int i = 0; i < 10; ++i) {
    if (i < 5) {
      dyn_array_push((void **)&arr, &i);
      printf("Added %d to arrray\n", i);
    } else {
      int *d = dyn_array_pop(arr);
      printf("The output of the array is %d\n", *d);
      assert((4 - (i - 5)) == *d && "Not expected output");
    }
  }
  printf(GREEN "Test Succesfully Completed\n" WHITE);
}
