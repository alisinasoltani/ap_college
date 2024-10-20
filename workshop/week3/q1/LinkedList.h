#include "types.h"

#ifndef __LIST__
    #define __LIST__
    class LinkedList {
        private:
            Node* head;
            Node* tail;
        public:
            LinkedList();
            LinkedList(int size, int value);
            LinkedList(const LinkedList &list);
            void push_back(int new_value);
            void push_front(int new_value);
            int pop_back();
            int pop_front();
            bool is_empty();
            // ~LinkedList();
            int at(int index);
            void printAllNodes();
            Node* createNode(int value);
    };
#endif