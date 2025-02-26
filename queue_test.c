#include "queue.h"
#include <assert.h>
#include <stdio.h>

#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define RED "\033[31m"

int main() {
  int data[9999];

  Queue tq = {.capacity = 9999, .data = data, .head = -1};

  // Fill queue
  for (int i = 0; i < 10000; ++i) {
    enqueue(&tq, i);
    printf("Added %d to queue\n", i);
  }

  assert(isFull(&tq) && "List was not full");

  // Empty queue
  for (int i = 9999; i >= 0; --i) {
    int d = dequeue(&tq);
    printf("The output of the queue is %d\n", d);
    assert(i == d && RED "Not expected output" WHITE);
  }
  assert(isEmpty(&tq) && RED "List was not empty" WHITE);
  printf(GREEN "Test Succesfully Completed\n" WHITE);
}
