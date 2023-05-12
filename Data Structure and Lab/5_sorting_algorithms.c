/*
This code sorts an array of integers using one of five different sorting
algorithms:
1. Insertion sort
2. Selection sort
3. Bubble sort
4. Merge sort
5. Quick sort

Author: Wahid Sadik
Created: 25-02-2023
*/

#include <stdio.h>

void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void merge_sort_recursion(int arr[], int l, int u);
void merge_sorted_arrays(int arr[], int l, int m, int u);
void swap(int *a, int *b);
void quicksort_recursion(int arr[], int l, int u);
int quicksort_partition(int arr[], int l, int u);
void printarray(int arr[], int n);

int main() {
  int n;
  int key;
  printf("How many numbers you wanna enter?\n");
  scanf("%d", &n);
  int arr[n];
  printf("Please enter %d terms:\n", n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  printf("Which type of sort you wanna perform?\n");
  printf("1.Insertion\n2.Selection\n3.Bubble\n4.Merge\n5.Quick\n");
  printf("Type the corresponding number:\n");
  scanf("%d", &key);
  switch (key) {
    case 1:
      insertion_sort(arr, n);
      break;
    case 2:
      selection_sort(arr, n);
      break;
    case 3:
      bubble_sort(arr, n);
      break;
    case 4:
      merge_sort_recursion(arr, 0, n - 1);
      break;
    case 5:
      quicksort_recursion(arr, 0, n - 1);
      break;
    default:
      break;
  }
  printf("Sorted array:\n");
  printarray(arr, n);
  return 0;
}

void insertion_sort(int arr[], int n) {
  int element;
  for (int i = 1; i < n; i++) {
    element = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > element) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = element;
  }
}

void selection_sort(int arr[], int n) {
  int smallestIndex, temp;
  for (int i = 0; i < n - 1; i++) {
    smallestIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[smallestIndex]) smallestIndex = j;
    }
    temp = arr[i];
    arr[i] = arr[smallestIndex];
    arr[smallestIndex] = temp;
  }
}

void bubble_sort(int arr[], int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

//    merge_sort_recursion function everytime divide the array in between until
//    it gets to a single number
void merge_sort_recursion(int arr[], int l, int u) {
  if (l >= u) return;
  int m = l + (u - l) / 2;  // mid is the middle index based on the lower index
                            // and upper index of this function
  merge_sort_recursion(arr, l,
                       m);  // here by using recursion method we are calling the
                            // function but every time with different m
  merge_sort_recursion(arr, m + 1, u);  // middle index + 1 to upper index
  merge_sorted_arrays(arr, l, m,
                      u);  // array, lower index, middle index and upper index
}

//    merge_sorted_arrays function every time reconstract the single number and
//    sort them
void merge_sorted_arrays(int arr[], int l, int m, int u) {
  int leftarr_length = m - l + 1;
  int rightarr_length = u - m;
  int leftarr[leftarr_length];
  int rightarr[rightarr_length];
  int i, j, k;
  for (int i = 0; i < leftarr_length; i++)
    leftarr[i] = arr[l + i];  // copying the lower l elements of arr to new left
                              // arr until the loop condition
  for (int i = 0; i < rightarr_length; i++)
    rightarr[i] = arr[m + 1 + i];  // again copying from arr but this time from
                                   // middle + 1 until upper bound
  for (i = 0, j = 0, k = l; k <= u;
       k++) {  // here k index is controlling the loop going form l to u
    if ((i <
         leftarr_length) &&  // it means left array index is between the length
        (j >= rightarr_length ||  // it means right array index is outside the
                                  // right array
         leftarr[i] <= rightarr[j])) {
      arr[k] = leftarr[i];
      i++;
    } else {
      arr[k] = rightarr[j];
      j++;
    }
  }
}

void swap(int *a, int *b) {  // this is for swapping array elements in
                             // quicksort_partition function
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quicksort_recursion(int arr[], int l, int u) {
  if (l >= u)  // when the lower index is equal or greater then upper then we
               // should stop this recursive function
    return;
  int pivotIndex = quicksort_partition(
      arr, l, u);  // calling quicksort_partition func to get the pivot index
  quicksort_recursion(arr, l,
                      pivotIndex - 1);  // recursive call to this function with
                                        // lower index and pivotIndex - 1
  quicksort_recursion(
      arr, pivotIndex + 1,
      u);  // same as before but this time pivotIndex + 1 as lower value
}

int quicksort_partition(int arr[], int l, int u) {
  int pivot = arr[l];
  int i = l;  // this is for going from lower index to upper
  int j = u;  // this is for going from upper index to lower
  while (i < j) {
    while (arr[i] <= pivot)  // comparision to pivot from lower index
      i++;  // as the while condition is satisfied so we are incresing the lower
            // index
    while (arr[j] > pivot) j--;
    if (i < j) swap(&arr[i], &arr[j]);
  }
  swap(&arr[l], &arr[j]);
  return j;
}

void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}
