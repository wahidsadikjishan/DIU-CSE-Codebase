/*
Binary search tree implementation

Author: Wahid Sadik
Created: 13-05-2023
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data);
node* insert_node(node* root, int data);
bool search(node* root, int data);

int main() {
  node* root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 20);
  root = insert_node(root, 30);
  root = insert_node(root, 40);
  root = insert_node(root, 50);
  int num;
  printf("Enter a number to be searched in the tree: ");
  scanf("%d", &num);
  if (search(root, num) == true) {
    printf("The number %d is present in the tree.\n", num);
  } else {
    printf("The number %d is not present in the tree.\n", num);
  }
  return 0;
}

node* create_node(int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node* insert_node(node* root, int data) {
  if (root == NULL) {
    root = create_node(data);
  } else if (data <= root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

bool search(node* root, int data) {
  if (root == NULL) {
    return false;
  } else if (root->data == data) {
    return true;
  } else if (data <= root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}