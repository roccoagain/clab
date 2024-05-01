#pragma once

// LIFO stack definition
typedef struct {
  void** elements;
  int size;
  int top;
} lifo;

// Returns pointer to new LIFO or NULL pointer on failure
lifo* newLifo(int size);

// Free LIFO stack and its elements
void deleteLifo(lifo* q);

// Returns 1 if LIFO stack is empty, 0 otherwise
int isEmptyLifo(lifo* q);

// Push element to LIFO stack. Returns 0 if successful
int putLifo(lifo* q, void* element);

// Pop top element from LIFO stack. Returns 0 if successful
int getLifo(lifo* q, void** element);

// Print all elements of LIFO stack
void printLifo(lifo* q, void (*print)(void const* element));
