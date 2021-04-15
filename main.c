/*==============================================================================
  Singly Linked List
==============================================================================*/

#include <stdio.h>
#include "linked_list.h"

int main(int argc, const char **argv)
{
    printf("Testing linked list...\n");

    push_item("five");
    print_list();
    push_item("four");
    print_list();
    push_item("three");
    print_list();
    push_item("two");
    print_list();
    push_item("one");
    print_list();

    printf("---------\n");
    for (int idx = -1; idx < 6; idx++) {
        const char *item = get_item(idx);
        printf("%d: %s\n", idx, item == NULL ? "NOT_FOUND": item);
    }

    printf("---------\n");
    int idx = 2;
    bool res = remove_item(idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list();

    idx = -1;
    res = remove_item(idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list();

    idx = 10;
    res = remove_item(idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list();

    idx = 0;
    res = remove_item(idx);
    printf("removing %d, success: %s\n", idx, res ? "true" : "false");
    print_list();

    destroy_list();

    return 0;
}
