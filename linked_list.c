/*==============================================================================
  Singly Linked List
==============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"

// global variable to store the list
Node *linked_list = NULL;

// push string onto front of list
void push_item(const char *value)
{
    char *str = malloc(sizeof(char) * strlen(value));
    strcpy(str, value);

    Node *first = malloc(sizeof(Node));
    first->value = str;
    first->next = linked_list;

    linked_list = first;
}

const char *get_item(int i)
{
    if (i < 0) {
        return NULL;
    }

    Node *curr = linked_list;
    int j = 0;

    while (j <= i) {
        curr = curr->next;
        j++;
    }

    return curr->value;
}

bool remove_item(int i)
{
    if (i < 0) {
        return false;
    }

    Node *curr = linked_list;
    Node *prev = NULL;
    int j = 0;

    while (j <= i) {
        prev = curr;
        curr = curr->next;
        j++;
    }

    if (curr == NULL) {
        return false;
    }

    // join previous node to next node.
    prev->next = curr->next;

    // free memory
    free(curr);
    free(curr);

    return true;
}

void print_list()
{
    Node *curr = linked_list;

    printf("[\n");

    while (curr != NULL) {
        printf("  \"%s\",\n", curr->value);
        curr = curr->next;
    }

    printf("]\n");
}

void destroy_list()
{
    while (linked_list != NULL) {
        Node *next = linked_list->next;

        free(linked_list->value);
        free(linked_list);

        linked_list = next;
    }
}

