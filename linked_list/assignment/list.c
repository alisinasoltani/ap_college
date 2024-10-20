#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "utils.h"

void appendFirst(Node** head , char* key, int val) {
    Node* first_node = (Node *)malloc(sizeof(Node));
    strcpy(first_node->key, key);
    first_node->val = val;
    first_node->next = NULL;
    *head = first_node;
    success("Node Appended Successfully!");
    printf("key: %s, value: %d\n", key, val);
}

void appendNode(Node** head, char* key, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        error("allocation failed!");
        return;
    }
    strcpy(new_node->key, key);
    new_node->val = val;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    
    success("Node Appended Successfully!");
    printf("key: %s, value: %d\n", new_node->key, new_node->val);
}


void printAll(Node* head) {
    Node* current_node = head;
    int node_counter = 0;
    while (current_node != NULL) {
        printf("%d: %s\t%d\n", node_counter, current_node->key, current_node->val);
        current_node = current_node->next;
        node_counter++;
    }
}

void printNode(Node* node) {
    if (node != NULL) {
        success("Node found!");
        printf("key: %s, value: %d\n", node->key, node->val);
    } else {
        error("Node is NULL!\n");
    }
}


Node* find(Node* head, char* key) {
    Node* current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

int deleteNode(Node** head, char* key) {
    Node* current_node = *head;
    Node* prev_node = NULL;
    if (current_node == NULL) {
        error("Invalid Head!");
        return 0;
    }
    if (strcmp(current_node->key, key) == 0) {
        info("deleted node was at the head.");
        *head = current_node->next;
        free(current_node);
        return 1;
    }
    while (current_node != NULL && strcmp(current_node->key, key) != 0) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return 0;
    }
    prev_node->next = current_node->next;
    free(current_node);
    return 1;
}
