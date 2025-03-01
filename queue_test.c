#include "queue.h"
#include <assert.h>
#include <stdio.h>

#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define RED "\033[31m"

int main() {
  int data[10];

  Queue tq = {.capacity = 10, .data = data, .head = -1, .tail = -1};

  // LINEAR TEST
  //  Fill queue
  for (int i = 0; i < 10; ++i) {
    enqueue(&tq, i);
    printf("Added %d to queue\n", i);
  }

  assert(isFull(&tq) && "List was not full");

  // Empty queue
  for (int i = 0; i < 10; ++i) {
    int d = dequeue(&tq);
    printf("The output of the queue is %d\n", d);
    assert(i == d && "Not expected output");
  }
  assert(isEmpty(&tq) && "List was not empty");

  for (int i = 0; i < 10; ++i) {
    if (i < 5) {
      enqueue(&tq, i);
      printf("Added %d to queue\n", i);
    } else {
      int d = dequeue(&tq);
      printf("The output of the queue is %d\n", d);
      assert((i - 5) == d && "Not expected output");
    }
  }

  assert(isEmpty(&tq) && "List was not empty");
  printf(GREEN "Test Succesfully Completed\n" WHITE);
}
