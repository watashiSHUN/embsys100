#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

int nextEmptySpot;

// LIFO stack is empty if nextEmptySpot is 0;
int stack_empty(void){
  return nextEmptySpot == 0 ? 1:0;
}
// LIFO stack is full if nextEmptySpot is STACK_SIZE;
int stack_full(void){
  return nextEmptySpot == STACK_SIZE? 1:0;
}
// Initialize internals of the stack
void stack_init(void)
{
    nextEmptySpot = 0;
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (stack_full()) {
        return -1;
    }
    StackStore[nextEmptySpot++] = data;
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (stack_empty()) {
        return -1;
    }
    *data = StackStore[--nextEmptySpot];
    return 0;
}
