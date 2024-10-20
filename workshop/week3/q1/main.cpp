#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list(4, 3);
    LinkedList &a = list;
    LinkedList list2(a);
    list2.printAllNodes();
}