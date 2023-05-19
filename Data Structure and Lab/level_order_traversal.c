#include <stdio.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data);
node* insert_node(node* root, int data);
void level_order_traversal(node* root);

int main() {
  node* root = NULL : insert_node(root, 15);
  insert_node(root, 10);
  insert_node(root, 20);
  insert_node(root, 7);
  insert_node(root, 11);
  insert_node(root, 17);
  insert_node(root, 27);

  level_order_traversal(root);
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

void level_order_traversal(node* root) {
  
}