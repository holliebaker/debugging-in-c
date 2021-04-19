/*==============================================================================
  Singly Linked List
==============================================================================*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _Node {
    char *value;
    struct _Node *next;
} Node;

// push string onto front of list
void push_item(Node **head, const char *value);

// retrieve the i-th element (0-idnexed), null if there is none
const char *get_item(Node *head, int i);

// remove element at index i. returns true if successful, false otherwise
bool remove_item(Node **head, int i);

// print list to standard out
void print_list(Node *head);

// frees all memory and sets list back to NULL
void destroy_list(Node **head);

#endif

