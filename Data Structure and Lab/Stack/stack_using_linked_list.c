/*
Linked-list implementation of stack

Author: Wahid Sadik
Created: 26-03-2023
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *top = NULL;

bool isEmpty();
void push(int data);
int pop();
int peek();

int main() {
  push(1000);
  push(2000);
  push(3000);
  push(4000);
  printf("Popped element is: %d\n", pop());
  printf("Popped element is: %d\n", pop());
  printf("Peeked element is: %d\n", peek());
  return 0;
}

bool isEmpty() {
  if (top == NULL) {
    return true;
  }
  return false;
}

void push(int data) {
  node *new_node = (node *)(malloc(sizeof(node)));
  new_node->data = data;
  if (isEmpty()) {
    new_node->next = NULL;
    top = new_node;
  } else {
    new_node->next = top;
    top = new_node;
  }
}

int pop() {
  if (isEmpty()) {
    return 0;
  }
  node *temp = top;
  int value = top->data;
  top = top->next;
  free(temp);
  temp = NULL;
  return value;
}

int peek() {
  if (isEmpty()) {
    return 0;
  }
  return top->data;
}