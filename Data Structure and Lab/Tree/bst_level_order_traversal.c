/*
This program implements a binary search tree and performs a level order
traversal.

Author: Wahid Sadik
Created: 20-05-2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data);
node* insert_node(node* root, int data);
void level_order_traversal(node* root);

int main() {
  node* root = NULL;

  // Insert nodes into the binary tree
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 70);
  root = insert_node(root, 60);
  root = insert_node(root, 80);

  // Perform level order traversal and print the nodes
  level_order_traversal(root);

  return 0;
}

// Create a new node with the given data
node* create_node(int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

// Insert a new node with the given data into the binary tree
node* insert_node(node* root, int data) {
  if (root == NULL) {
    return create_node(data);
  }

  if (data <= root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }

  return root;
}

// Perform level order traversal of the binary tree and print the nodes
void level_order_traversal(node* root) {
  if (root == NULL) {
    return;
  }

  node* queue[100];
  int rear = 0;
  int front = 0;

  queue[rear] = root;
  rear++;

  while (front < rear) {
    node* current = queue[front];
    front++;

    printf("%d ", current->data);

    if (current->left) {
      queue[rear] = current->left;
      rear++;
    }

    if (current->right) {
      queue[rear] = current->right;
      rear++;
    }
  }

  printf("\n");
}