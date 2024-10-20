#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#ifndef TYPES
    #define TYPES
    #include "types.h"
#endif

void appendRandomNodes__Test(Node** list) {
    int r = rand() % 10;
    printf(GREEN "Append Random Nodes:\n");
    printf("\t- Appended %d to the lists.\n" RESET, r);
    appendRandomNodes(list, r);
    printAllNodes(list);
}

int main() {
    srand(time(NULL));
    Node *head;
    head = malloc(sizeof(Node));
    head->next = NULL;
    head->value = 4;
    printf(GREEN "Linked List Test:\n" RESET);
    appendRandomNodes__Test(&head);
    return 0;
}