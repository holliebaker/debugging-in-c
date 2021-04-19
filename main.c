/*==============================================================================
  Singly Linked List
==============================================================================*/

#include <stdio.h>
#include "linked_list.h"

int main(int argc, const char **argv)
{
    printf("Testing linked list...\n");

    // initialising an empty list
    Node *my_list = NULL;

    push_item(&my_list, "five");
    print_list(my_list);
    push_item(&my_list, "four");
    print_list(my_list);
    push_item(&my_list, "three");
    print_list(my_list);
    push_item(&my_list, "two");
    print_list(my_list);
    push_item(&my_list, "one");
    print_list(my_list);

    printf("---------\n");
    int idx = -1;
    const char *item = get_item(my_list, idx);
    printf("%d: %s\n", idx, item == NULL ? "NOT_FOUND": item);

    idx = 100;
    item = get_item(my_list, idx);
    printf("%d: %s\n", idx, item == NULL ? "NOT_FOUND": item);

    for (int idx = -1; idx < 6; idx++) {
        item = get_item(my_list, idx);
        printf("%d: %s\n", idx, item == NULL ? "NOT_FOUND": item);
    }

    printf("---------\n");
    idx = 2;
    bool res = remove_item(&my_list, idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list(my_list);

    idx = -1;
    res = remove_item(&my_list, idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list(my_list);

    idx = 10;
    res = remove_item(&my_list, idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list(my_list);

    idx = 0;
    res = remove_item(&my_list, idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list(my_list);

    printf("before destroy_list(my_list): %p\n", my_list);
    destroy_list(&my_list);
    printf("after destroy_list(my_list): %p\n", my_list);

    return 0;
}
