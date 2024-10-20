#ifndef LIST_H
#define LIST_H

typedef struct node {
    char key[20];
    int val;
    struct node *next;
} Node;

void appendFirst(Node** head , char* key, int val);
void appendNode(Node** head , char* key, int val);
void printAll(Node* head);
void printNode(Node* node);
Node* find(Node* head, char* key);
int deleteNode(Node** head, char* key);

#endif