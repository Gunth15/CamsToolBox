// Static Queue data structure written in C by C.W

#include "queue.h"
#include <assert.h>

int dequeue(Queue *q) {
  assert((q->head > -1) && "BOUNDS ERROR: indexing after zero");
  return q->data[q->head--];
}

void enqueue(Queue *q, int item) {
  assert((q->head < q->capacity) && "BOUNDS ERROR: Past capacity");
  q->data[++q->head] = item;
}
int peek(Queue *q) { return q->data[q->head]; }
bool isEmpty(Queue *q) { return q->head == -1; }
bool isFull(Queue *q) { return q->head == q->capacity; }
