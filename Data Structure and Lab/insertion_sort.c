/*
Insertion sort

Author: Wahid Sadik
Created: 17-05-2023
*/

#include <stdio.h>

void insertion_sort(int arr[], int n);

int main() {
  int arr[5];
  int n = 5;
  printf("Enter 5 numbers: ");
  for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
  printf("Sorted: ");
  insertion_sort(arr, n);
  return 0;
}

void insertion_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int current_index = i;
    int current_value = arr[i];
    while (current_index > 0 && arr[current_index - 1] > current_value) {
      arr[current_index] = arr[current_index - 1];
      current_index--;
    }
    arr[current_index] = current_value;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
