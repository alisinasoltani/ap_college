#include <iostream>
#include "LinkedList.h"
#include "types.h"
#include "terminal_colors.h"

using namespace std;

LinkedList::LinkedList() {
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
}

LinkedList::LinkedList(int size, int value) {
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
    for (int i = 0; i < size; i++) {
        LinkedList::push_front(i);
    }
    LinkedList::printAllNodes();
}

LinkedList::LinkedList(const LinkedList &list) {
    Node *current_new_head;
    if (list.head == nullptr) {
        LinkedList::head == nullptr;
        return;
    } else {
        LinkedList::head = new Node;
        LinkedList::head->data = list.head->data;
        LinkedList::head->Next = list.head->Next;
        LinkedList::head->previous = nullptr;
        current_new_head = LinkedList::head->Next;
    }
    for (Node *current = list.head->Next; current->Next; current = current->Next) {
        current_new_head->Next = new Node;
        current_new_head->Next->data = current->data;
        current_new_head->Next->previous = current->previous;
        current_new_head = current_new_head->Next;
    }
}

void LinkedList::push_back(int new_value) {
    Node* newNode = new Node();
    newNode->data = new_value;
    newNode->previous = nullptr;
    newNode->Next = nullptr;
    if (is_empty()) {
        LinkedList::head = newNode;
        LinkedList::tail = newNode;
    } else {
        LinkedList::tail->Next = newNode;
        newNode->previous = tail;
        LinkedList::tail = newNode;
    }
    LinkedList::printAllNodes();
}

void LinkedList::push_front(int new_value) {
    Node* newNode = new Node();
    newNode->data = new_value;
    newNode->previous = nullptr;
    newNode->Next = nullptr;
    if (is_empty()) {
        LinkedList::head = newNode;
        LinkedList::tail = newNode;
    } else {
        LinkedList::head->previous = newNode;
        newNode->Next = head;
        LinkedList::head = newNode;
    }
    LinkedList::printAllNodes();
}

bool LinkedList::is_empty() {
    if (LinkedList::head) {
        return false;
    } else {
        return true;
    }
}

void LinkedList::printAllNodes() {
    Node* current = LinkedList::head;
    int i = 0;
    printf(BLUE "\tThe List:\n" RESET);
    while (current != NULL) {
        printf("\t" BLUE "Node %d" RESET ":\t%d\n", i, current->data);
        current = current->Next;
        i++;
    }
}

Node* LinkedList::createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->Next = NULL;
    return newNode;
}
