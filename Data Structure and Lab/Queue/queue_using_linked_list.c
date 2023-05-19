/*
Linked list implementation of queue

Author: Wahid Sadik
Created: 13-05-2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int num);
void dequeue();
void print_queue();

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  dequeue();
  dequeue();
  print_queue();
  return 0;
}

void enqueue(int num) {
  node* temp = (node*)malloc(sizeof(node));
  temp->data = num;
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = temp;
    return;
  } else {
    rear->next = temp;
    rear = temp;
  }
}

void dequeue() {
  node* temp = front;
  if (front == NULL) {
    return;
  } else if (front == rear) {
    front = rear = NULL;
  } else {
    front = front->next;
  }
  free(temp);
}

void print_queue() {
  node* temp = front;
  if (front == NULL) {
    printf("The queue is empty\n");
    return;
  }
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}