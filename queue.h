// Static Queue data structure written in C by C.W
// For the sake of simplicity, generics have been entirely avoided
// Change the types when needed
#include <stdbool.h>
#include <stddef.h>

// Query head must be set to -1 and the capacity to the size of the array
typedef struct {
  int capacity;
  int head;
  int *data;
} Queue;

void InitQueue(Queue *q, int capacity); // Initializes queue with no data
int dequeue(Queue *q); // Dequeue from stack, Crashes program if you try to
                       // dequeue when there is no data
void enqueue(Queue *q, int item); // Enqueue to stack. Crashes if you try to
                                  // enqueue past capacity
int peek(Queue *q);     // Peeks whats in front of the queue. Completely safe
bool isEmpty(Queue *q); // Checks of queue is full
bool isFull(Queue *q);  // Checks if queue is empty
