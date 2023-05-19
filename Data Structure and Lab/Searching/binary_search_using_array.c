/*
Array implementation of binary search

Author: Wahid Sadik
Created: 04-03-2023
*/

#include <stdio.h>

int binary_search(int arr[], int n, int x);

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = 5;
  int x;
  printf("Enter a number that you want to find in the array\n");
  scanf("%d", &x);
  if ((binary_search(arr, n, x)) == -1)
    printf("Not Found!\n");
  else
    printf("%d found at index %d of the array\n", x, binary_search(arr, n, x));
  return 0;
}

int binary_search(int arr[], int n, int x) {
  int left = 0;
  int right = n - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == x)
      return mid;
    else if (x < arr[mid])
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}