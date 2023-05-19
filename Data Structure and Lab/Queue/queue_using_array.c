/*
Array implementation of queue

Author: Wahid Sadik
Created: 13-05-2023
*/

#include <stdio.h>

int arr[512];
int pos = 0;

void enqueue(int n);
void dequeue();

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  dequeue();
  dequeue();
  for (int i = 0; i < pos; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void enqueue(int n) {
  if (pos == 512) {
    printf("The queue is full!\n");
    return;
  }
  arr[pos] = n;
  pos++;
}

void dequeue() {
  if (pos == 0) {
    printf("The queue is empty\n");
    return;
  }
  int element = arr[0];
  for (int i = 0; i < pos; i++) {
    arr[i] = arr[i + 1];
  }
  pos--;
}