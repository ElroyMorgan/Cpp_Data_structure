//
// Created by elroy on 25-7-31.
//

#ifndef STACK_H
#define STACK_H

namespace stack {
    typedef struct Node {
        int data{};
        Node* next;
        Node():next(nullptr){}
    }Node;

    class Stack {
        Node* node{};
    public:
        Stack()=default;
        void push(int e);
        int pop();
    };
}
#endif //STACK_H
