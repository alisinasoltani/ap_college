#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"

int main() {
    Node* head = NULL;

    appendNode(&head, "first", 7);
    appendNode(&head, "second", 2);
    appendNode(&head, "third", 5);
    printAll(head);

    Node* founded = find(head, "second");
    if (founded != NULL) {
        printNode(founded);
    } else {
        error("Node not found!\n");
    }

    int ok = deleteNode(&head, "third");
    if (ok) {
        success("node deleted.");
    } else {
        error("node not found");
    }
    ok = deleteNode(&head, "first");
    if (ok) {
        success("node deleted.");
    } else {
        error("node not found");
    }
    ok = deleteNode(&head, "second");
    if (ok) {
        success("node deleted.");
    } else {
        error("node not found");
    }
    ok = deleteNode(&head, "second");
    if (ok) {
        success("node deleted.");
    } else {
        error("node not found");
    }
    printAll(head);
    return 0;
}
