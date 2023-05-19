/*
Binary search using recursion

Author: Wahid Sadik
Created: 10-03-2023
*/

#include <stdio.h>

int re_bs(int arr[], int low, int high, int x);

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  int x;
  printf("Enter a number: ");
  scanf("%d", &x);
  if ((re_bs(arr, 0, n - 1, x)) != -1)
    printf("%d found at index %d of the array\n", x, re_bs(arr, 0, n - 1, x));
  else
    printf("Not Found!\n");
  return 0;
}

int re_bs(int arr[], int low, int high, int x) {
  if (low > high) return -1;
  int mid = (low + high) / 2;
  if (arr[mid] == x)
    return mid;
  else if (x < arr[mid]) {
    high = mid - 1;
    int res = re_bs(arr, low, high, x);
    if (res != -1) return res;
  } else {
    low = mid + 1;
    int res = re_bs(arr, low, high, x);
    if (res != -1) return res;
  }
  return -1;
}