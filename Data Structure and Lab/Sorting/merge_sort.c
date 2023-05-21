/*
Merge sort

Author: Wahid Sadik
Created: 18-05-2023
*/

#include <stdio.h>

void merge_sort(int arr[], int left_index, int right_index);
void merge(int arr[], int left_index, int mid_index, int right_index);

int main() {
  int arr[5];
  printf("Enter 5 numbers: ");
  for (int i = 0; i < 5; i++) {
    scanf("%d", &arr[i]);
  }
  // sort the array
  merge_sort(arr, 0, 4);
  // print the sorted array
  printf("Sorted: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void merge_sort(int arr[], int left_index, int right_index) {
  // base case
  if (left_index >= right_index) return;
  // calculate middle index
  int mid_index = left_index + (right_index - left_index) / 2;
  // sort left and right halves of the array
  merge_sort(arr, left_index, mid_index);
  merge_sort(arr, mid_index + 1, right_index);
  // merge the two sorted halves
  merge(arr, left_index, mid_index, right_index);
}

void merge(int arr[], int left_index, int mid_index, int right_index) {
  // calculate length of left and right halves
  int left_arr_len = (mid_index - left_index) + 1;
  int right_arr_len = (right_index - mid_index);
  // create left and right sub-arrays
  int left_arr[left_arr_len];
  int right_arr[right_arr_len];
  // copy values from main array to sub-arrays
  for (int i = 0; i < left_arr_len; i++) {
    left_arr[i] = arr[left_index + i];
  }
  for (int i = 0; i < right_arr_len; i++) {
    right_arr[i] = arr[mid_index + 1 + i];
  }
  // declaration of variables to merge the sub-arrays back into the main array
  int left_merged_index, right_merged_index, merged_index;
  left_merged_index = right_merged_index = 0;
  merged_index = left_index;
  // compare values in left and right arrays and copy into main array
  while (left_merged_index < left_arr_len &&
         right_merged_index < right_arr_len) {
    if (left_arr[left_merged_index] <= right_arr[right_merged_index]) {
      arr[merged_index] = left_arr[left_merged_index];
      merged_index++;
      left_merged_index++;
    } else {
      arr[merged_index] = right_arr[right_merged_index];
      merged_index++;
      right_merged_index++;
    }
  }
  // copy any remaining values from left array
  while (left_merged_index < left_arr_len) {
    arr[merged_index] = left_arr[left_merged_index];
    merged_index++;
    left_merged_index++;
  }
  // copy any remaining values from right array
  while (right_merged_index < right_arr_len) {
    arr[merged_index] = right_arr[right_merged_index];
    merged_index++;
    right_merged_index++;
  }
}