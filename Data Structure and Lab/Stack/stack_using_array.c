/*
This Code uses an array to implement a stack data structure and provides
basic stack operations like push, pop, and peek.

Author: Wahid Sadik
Created: 25-03-2023
*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

bool isFull();
bool isEmpty();
void push(int data);
void pop();
void peek();

int main() {
  push(100);
  push(200);
  push(300);
  push(400);
  push(500);
  pop();
  pop();
  peek();
  return 0;
}

bool isFull() {
  if (top == MAX_SIZE - 1) {
    return true;
  }
  return false;
}

bool isEmpty() {
  if (top == -1) {
    return true;
  }
  return false;
}

void push(int data) {
  if (isFull()) {
    printf("Stack Overflow!\n");
    return;
  }
  top++;
  arr[top] = data;
}

void pop() {
  if (isEmpty()) {
    printf("Stack Underflow\n");
    return;
  }
  printf("Popped element: %d\n", arr[top]);
  top--;
}

void peek() {
  if (isEmpty()) {
    printf("Stack is empty\n");
  }
  printf("Peaked element: %d\n", arr[top]);
}