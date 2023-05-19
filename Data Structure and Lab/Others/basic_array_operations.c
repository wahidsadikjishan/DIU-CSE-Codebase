/*
Basic array operations: Insertion (ordered), Deletion (ordered), Traverse.

Author: Wahid Sadik
Created: 26-03-2023
*/

#include <stdio.h>

int main() {
  int arr[100] = {10, 20, 30, 40, 50, 60};
  int arr_size = 6;
  // traverseing the array before inserting
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  // inserting 35 at index 3 (and maintaining order)
  int ind = 3;
  int element = 35;
  for (int i = arr_size - 1; i >= ind; i--) {
    arr[i + 1] = arr[i];
  }
  arr[ind] = element;
  arr_size++;
  // traverseing the array after inserting
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  // deleting an element at index 4 (and maintainnig order);
  ind = 4;
  for (int i = ind; i < arr_size; i++) {
    arr[i] = arr[i + 1];
  }
  arr_size--;
  // traverseing the array after deleting
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}