// Static Queue data structure written in C by C.W
#include <stddef.h>

typedef struct {
  int capacity;
  size_t *head;
  size_t *data;
} Queue;

void InitQueue(Queue *q, int capacity); // Initializes queue with no data
size_t dequeue(Queue *q); // Dequeue from stack, Crashes program if you try to
                          // dequeue when there is no data
void enqueue(Queue *q, size_t item); // Enqueue to stack. Crashes if you try to
                                     // enqueue past capacity
size_t peek(Queue *q); // Peeks whats in front of the queue. Completely safe
