/*
Selection sort

Author: Wahid Sadik
Created: 17-05-2023
*/

#include <stdio.h>

void selection_sort(int arr[], int n);

int main() {
  int arr[5];
  int n = 5;
  printf("Enter 5 numbers: ");
  for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
  printf("Sorted: ");
  selection_sort(arr, n);
  return 0;
}

void selection_sort(int arr[], int n) {
  int min_num_index, temp;
  for (int i = 0; i < n - 1; i++) {
    int min_num_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_num_index]) {
        min_num_index = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min_num_index];
    arr[min_num_index] = temp;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}