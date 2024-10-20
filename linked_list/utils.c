#include <stdio.h>
#ifndef TYPES
    #define TYPES
    #include "types.h"
#endif
#include "utils.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void appendRandomNodes(Node **head, int number) {
    for (int i = 0; i < number; i++) {
        int r = (rand() * (i + 1)) % 10;
        appendNode(head, r);
    }
}

void printAllNodes(Node** list) {
    Node* current = *list;
    int i = 0;
    printf(BLUE "\tThe List:\n" RESET);
    while (current != NULL) {
        printf("\t" BLUE "Node %d" RESET ":\t%d\n", i, current->value);
        current = current->next;
        i++;
    }
}

Node* indexNode(Node** list, int index);
Node* findNode(Node** list, int value);

Node* find(Node** head, char* key);
int deleteNode(Node** head,char* key);

Node* deleteNode(Node** list, int index);
Node* placeNode(Node** list, Node* new_node, int index);
Node* replaceNode(Node** list, int new_value, int index);