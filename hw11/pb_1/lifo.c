#include "lifo.h"

#include <stdio.h>
#include <stdlib.h>

lifo* newLifo(int size) {
  if (size <= 0) {
    return NULL;
  }
  lifo* q = (lifo*)malloc(sizeof(lifo));
  if (q == NULL) {
    return NULL;
  }
  q->elements = (void**)malloc(size * sizeof(void*));
  if (q->elements == NULL) {
    free(q);
    return NULL;
  }
  q->size = size;
  q->top = -1;
  return q;
}

void deleteLifo(lifo* q) {
  if (q != NULL) {
    free(q->elements);
    free(q);
  }
}

int isEmptyLifo(lifo* q) {
  if (q == NULL) return 1;
  return q->top == -1;
}

int putLifo(lifo* q, void* element) {
  if (q == NULL || q->top >= q->size - 1) {
    return 1;
  }
  ++q->top;
  q->elements[q->top] = element;
  return 0;
}

int getLifo(lifo* q, void** element) {
  if (isEmptyLifo(q)) {
    *element = NULL;
    return 1;
  }
  *element = q->elements[q->top];
  q->top--;
  return 0;
}

void printLifo(lifo* q, void (*print)(void const* element)) {
  printf("{ ");
  for (int i = q->top; i >= 0; i--) {
    print(q->elements[i]);
    if (i > 0) printf(", ");
  }
  printf(" }\n");
}
