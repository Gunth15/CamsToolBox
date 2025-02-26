#include "queue.h"
#include <stdio.h>

int main() {
  Queue tq;

  InitQueue(&tq, 10);
  // should fail
  for (int i = 0; i < 10; ++i) {
    enqueue(&tq, i);
    printf("Added %d to queue", i);
  }
  for (int i = 0; i < 10; ++i) {
    printf("The out put of the queue is %d", (int)dequeue(&tq));
  }
}
