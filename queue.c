// Static Queue data structure written in C by C.W

#include "queue.h"
#include <assert.h>

void InitQueue(Queue *q, int capacity) {
  size_t data[capacity];
  q->capacity = capacity;
  q->data = data;
  q->head = &data[0];
}

size_t dequeue(Queue *q) {
  int head_locat = (q->head - q->data);
  assert(head_locat >= 0 && "Error: Tried to index invalid position that is "
                            "less than 0. Did you peek?");
  return *(q->head--);
}

void enqueue(Queue *q, size_t item) {
  int head_locat = (q->head - q->data);
  if (head_locat != 0) {
    ++q->head;
  }
  assert(head_locat < q->capacity &&
         "Error: Tried to index invalid position that is greater than "
         "capacity. Did you peek first?");
  *(q->head) = item;
}

size_t peek(Queue *q) { return *(q->head); }
