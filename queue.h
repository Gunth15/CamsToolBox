#ifndef GENERIC_QUEUE_H
#define GENERIC_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEF_STATIC_QUEUE(TYPE, NAME, CAPACITY)                              \
typedef struct {                                                        \
    TYPE data[CAPACITY];                                                \
    int head;                                                           \
    int tail;                                                           \
} NAME;                                                                 \
                                                                        \
static inline void NAME##_init(NAME *q) {                               \
    q->head = -1;                                                       \
    q->tail = -1;                                                       \
}                                                                       \
                                                                        \
static inline bool NAME##_isEmpty(const NAME *q) {                      \
    return q->head == -1;                                               \
}                                                                       \
                                                                        \
static inline bool NAME##_isFull(const NAME *q) {                       \
    return (q->head == (q->tail + 1) % CAPACITY);                    \
}                                                                       \
                                                                        \
static inline void NAME##_enqueue(NAME *q, TYPE item) {                 \
    if (NAME##_isFull(q)) {                                             \
        fprintf(stderr, "Queue full\n");                                \
        exit(EXIT_FAILURE);                                             \
    }                                                                   \
    if (NAME##_isEmpty(q))                                              \
        q->head = 0;                                                    \
    q->tail = (q->tail + 1) % CAPACITY;                              \
    q->data[q->tail] = item;                                            \
}                                                                       \
                                                                        \
static inline TYPE NAME##_dequeue(NAME *q) {                            \
    if (NAME##_isEmpty(q)) {                                            \
        fprintf(stderr, "Queue empty\n");                               \
        exit(EXIT_FAILURE);                                             \
    }                                                                   \
    TYPE val = q->data[q->head];                                        \
    if (q->head == q->tail)                                             \
        q->head = q->tail = -1;                                         \
    else                                                                \
        q->head = (q->head + 1) % CAPACITY;                          \
    return val;                                                         \
}                                                                       \
                                                                        \
static inline TYPE NAME##_peek(const NAME *q) {                         \
    if (NAME##_isEmpty(q)) {                                            \
        fprintf(stderr, "Queue empty\n");                               \
        exit(EXIT_FAILURE);                                             \
    }                                                                   \
    return q->data[q->head];                                            \
}

#endif

