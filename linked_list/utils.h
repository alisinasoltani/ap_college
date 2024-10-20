#ifndef TYPES
    #define TYPES
    #include "types.h"
#endif
#include <stdlib.h>
#include <time.h>

Node* createNode(int data);
void printAllNodes(Node** list);
void appendRandomNodes(Node **head, int number);
Node* indexNode(Node** list, int index);
Node* findNode(Node** list, int value);
Node* deleteNode(Node** list, int index);
Node* placeNode(Node** list, Node* new_node, int index);
Node* replaceNode(Node** list, int new_value, int index);