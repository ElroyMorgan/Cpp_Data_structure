//
// Created by elroy on 25-7-31.
//

#include "../include/stack.h"
namespace stack {
    void Stack::push(const int e) {
        const auto p=new Node();
        p->data=e;
        p->next=node;
        node=p;
    }
    int Stack::pop() {
        const auto p=node;
        const auto value=p->data;
        node=node->next;
        delete p;
        return value;
    }
}