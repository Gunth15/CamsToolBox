#ifndef GENERIC_DYN_QUEUE_H
#define GENERIC_DYN_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEF_DYN_QUEUE(T, NAME)                                                 \
  typedef struct {                                                             \
    T data;                                                                    \
    void *next;                                                                \
  } NAME##_Node;                                                               \
  typedef struct {                                                             \
    NAME##_Node *head;                                                         \
    NAME##_Node *tail;                                                         \
  } NAME;                                                                      \
  static inline void NAME##_init(NAME *q) {                                    \
    q->head = NULL;                                                            \
    q->tail = q->head;                                                         \
    return;                                                                    \
  }                                                                            \
  static inline bool NAME##_isEmpty(NAME *q) { return q->head == NULL; }       \
  static inline T NAME##_peek(NAME *q) { return q->head->data; }               \
  static inline int NAME##_enqueue(NAME *q, T data) {                          \
    NAME##_Node *new_node = (NAME##_Node *)malloc(sizeof(NAME##_Node));        \
    if (!new_node)                                                             \
      return 0;                                                                \
    new_node->data = data;                                                     \
    new_node->next = NULL;                                                     \
    if (!q->head && !q->tail) {                                                \
      q->head = new_node;                                                      \
      q->tail = new_node;                                                      \
    } else {                                                                   \
      q->tail->next = new_node;                                                \
      q->tail = new_node;                                                      \
    }                                                                          \
    return 1;                                                                  \
  }                                                                            \
  static inline T NAME##_dequeue(NAME *q) {                                    \
    NAME##_Node *top = q->head;                                                \
    q->head = (NAME##_Node *)top->next;                                        \
    T data = top->data;                                                        \
    if (!q->head)                                                              \
      q->tail = NULL;                                                          \
    free(top);                                                                 \
    return data;                                                               \
  }                                                                            \
  static inline void NAME##_deinit(NAME *q) {                                  \
    NAME##_Node *node = q->head;                                               \
    while (node) {                                                             \
      NAME##_Node *next_node = (NAME##_Node *)node->next;                      \
      free(node);                                                              \
      node = next_node;                                                        \
    }                                                                          \
  }
#endif
