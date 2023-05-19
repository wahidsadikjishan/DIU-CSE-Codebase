/*
This file contains all basic linked-list operations including:
Insertion
Deletion
Traverse

Author: Wahid Sadik
Date: 25-03-2023
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Function declarations
void insert_at_beginning(node **head, int new_data);
void insert_at_end(node **head, int new_data);
void insert_at_specific(node **head, int position, int new_data);
void deletion_at_beginning(node **head);
void deletion_at_end(node **head);
void deletion_at_specific(node **head, int position);
void traverse_and_print(node *head);
void traverse_and_count(node *head);
void traverse_and_find(node *head, int data);

int main() {
  node *head = NULL;
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_end(&head, 30);
  insert_at_end(&head, 40);
  insert_at_specific(&head, 3, 50);
  insert_at_specific(&head, 3, 60);
  deletion_at_beginning(&head);
  deletion_at_end(&head);
  deletion_at_specific(&head, 2);
  traverse_and_print(head);
  traverse_and_count(head);
  traverse_and_find(head, 50);
  // Free memory before exiting the program
  node *current = head;
  node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  return 0;
}

// Inserts a node at the beginning of the list
void insert_at_beginning(node **head, int new_data) {
  // Allocate memory for the new node
  node *new_node = (node *)malloc(sizeof(node));
  // Set the data of the new node
  new_node->data = new_data;
  // If the list is empty, set the new node as the head
  if (*head == NULL) {
    new_node->next = NULL;
    *head = new_node;
  } else {
    // Otherwise, set the new node's next pointer to the current head, and set
    // the head to the new node
    new_node->next = *head;
    *head = new_node;
  }
}

// Inserts a node at the end of the list
void insert_at_end(node **head, int new_data) {
  // Set a temporary pointer to the head
  node *temp = *head;
  // Allocate memory for the new node
  node *new_node = (node *)malloc(sizeof(node));
  // Set the data of the new node
  new_node->data = new_data;
  // Set the new node's next pointer to NULL
  new_node->next = NULL;
  // Iterate through the list until the last node is reached
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // Set the last node's next pointer to the new node
  temp->next = new_node;
}

// Inserts a node at a specific position in the list
void insert_at_specific(node **head, int position, int new_data) {
  // Set a temporary pointer to the head
  node *temp = *head;
  // Allocate memory for the new node
  node *new_node = (node *)malloc(sizeof(node));
  // Set the data of the new node
  new_node->data = new_data;
  // Iterate through the list until the specified position is reached
  for (int i = 1; i < position - 1; i++) {
    temp = temp->next;
  }
  // Set the new node's next pointer to the node at the specified position
  new_node->next = temp->next;
  // Set the node at the specified position's next pointer to the new node
  temp->next = new_node;
}

// Deletes the node at the beginning of the list
void deletion_at_beginning(node **head) {
  // Set a temporary pointer to the head
  node *temp = *head;
  // If the list is empty, return
  if (*head == NULL) {
    return;
  } else {
    // Otherwise, set the head to the second node and free the memory of the
    // first node
    *head = temp->next;
    free(temp);
  }
}

// Deletes the node at the end of the list
void deletion_at_end(node **head) {
  // Set a temporary pointer to the head
  node *last = *head;
  // If the list is empty, return
  if (*head == NULL) {
    return;
  }
  // If there is only one node in the list, free the memory and set the head to
  // NULL
  if (last->next == NULL) {
    free(last);
    *head = NULL;
    return;
  }
  // Iterate through the list until the second-to-last node is reached
  while (last->next->next != NULL) {
    last = last->next;
  }
  // Free the memory of the last node and set the second-to-last node's next
  // pointer to NULL
  free(last->next);
  last->next = NULL;
}

// Deletes the node at a specific position in the list
void deletion_at_specific(node **head, int position) {
  // Set a temporary pointer to the head
  node *pos = *head;
  // If the list is empty, return
  if (*head == NULL) {
    return;
  }
  // If the position is the first node, set the head to the second node and free
  // the memory of the first node
  if (position == 1) {
    *head = pos->next;
    free(pos);
    return;
  }
  // Iterate through the list until the node before the specified position is
  // reached
  for (int i = 1; i < position - 1 && pos->next != NULL; i++) {
    pos = pos->next;
  }
  // If the node at the specified position does not exist, return
  if (pos->next == NULL) {
    return;
  }
  // Set the node before the specified position's next pointer to the node after
  // the specified position
  node *temp = pos->next;
  pos->next = pos->next->next;
  free(temp);
}

// Traverses the list and prints the data of each node
void traverse_and_print(node *head) {
  // Set a temporary pointer to the head
  node *temp = head;
  // Iterate through the list and print the data of each node
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

// Traverses the list and counts the number of nodes
void traverse_and_count(node *head) {
  // Set a temporary pointer to the head
  node *temp = head;
  int i;
  // Iterate through the list and increment a counter
  for (i = 1; temp != NULL; i++) {
    temp = temp->next;
  }
  // Print the number of nodes
  printf("There are %d node(s) in the list\n", --i);
}

// Traverses the list and finds the position of a specified data
void traverse_and_find(node *head, int data) {
  // Set a temporary pointer to the head
  node *temp = head;
  // Iterate through the list and compare the data of each node to the specified
  // data
  for (int i = 1; temp != NULL; i++) {
    if (temp->data == data) {
      printf("%d found at position %d\n", data, i);
    }
    temp = temp->next;
  }
}