/*==============================================================================
  Singly Linked List
==============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"

// push string onto front of list
void push_item(Node **head, const char *value)
{
    char *str = malloc(sizeof(char) * strlen(value));
    strcpy(str, value);

    Node *first = malloc(sizeof(Node));
    first->value = str;
    first->next = *head;

    *head = first;
}

const char *get_item(Node *head, int i)
{
    if (i < 0) {
        return NULL;
    }

    Node *curr = head;
    int j = 0;

    while (j <= i) {
        curr = curr->next;
        j++;
    }

    return curr->value;
}

bool remove_item(Node **head, int i)
{
    if (i < 0) {
        return false;
    }

    Node *curr = *head;
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

void print_list(Node *head)
{
    Node *curr = head;

    printf("[\n");

    while (curr != NULL) {
        printf("  \"%s\",\n", curr->value);
        curr = curr->next;
    }

    printf("]\n");
}

void destroy_list(Node **head)
{
    while (*head != NULL) {
        Node *next = (*head)->next;

        free((*head)->value);
        free(*head);

        *head = next;
    }
}

