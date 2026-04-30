#include "dyn_queue.h"
#include <assert.h>
#include <stdio.h>

#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define RED "\033[31m"

int main() {
  Queue tq;
  Queue_init(&tq);

  // LINEAR TEST
  //  Fill queue
  for (int i = 0; i < 10; ++i) {
    Queue_enqueue(&tq, i);
    printf("Added %d to queue\n", i);
  }

  assert(!Queue_isEmpty(&tq) && "List was not full");

  // Empty queue
  for (int i = 0; i < 10; ++i) {
    int d = Queue_dequeue(&tq);
    printf("The output of the queue is %d\n", d);
    assert(i == d && "Not expected output");
  }
  assert(Queue_isEmpty(&tq) && "List was not empty");

  for (int i = 0; i < 10; ++i) {
    if (i < 5) {
      Queue_enqueue(&tq, i);
      printf("Added %d to queue\n", i);
    } else {
      int d = Queue_dequeue(&tq);
      printf("The output of the queue is %d\n", d);
      assert((i - 5) == d && "Not expected output");
    }
  }

  assert(Queue_isEmpty(&tq) && "List was not empty");
  printf(GREEN "Test Succesfully Completed\n" WHITE);
}
