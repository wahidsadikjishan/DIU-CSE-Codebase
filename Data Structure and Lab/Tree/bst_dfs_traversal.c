#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data);
node* insert_node(node* root, int data);
void pre_order_traversal(node* root);
void in_order_traversal(node* root);
void post_order_traversal(node* root);

int main() {
  node* root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 70);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 60);
  root = insert_node(root, 80);
  printf("Preorder: ");
  pre_order_traversal(root);
  printf("\n");
  printf("Inorder: ");
  in_order_traversal(root);
  printf("\n");
  printf("Postorder: ");
  post_order_traversal(root);
  printf("\n");
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
    return create_node(data);
  }
  if (data <= root->data) {
    root->left = insert_node(root->left, data);
  }
  if (data > root->data) {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void pre_order_traversal(node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  pre_order_traversal(root->left);
  pre_order_traversal(root->right);
}

void in_order_traversal(node* root) {
  if (root == NULL) {
    return;
  }
  in_order_traversal(root->left);
  printf("%d ", root->data);
  in_order_traversal(root->right);
}

void post_order_traversal(node* root) {
  if (root == NULL) {
    return;
  }
  post_order_traversal(root->left);
  post_order_traversal(root->right);
  printf("%d ", root->data);
}