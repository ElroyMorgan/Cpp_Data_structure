//
// Created by elroy on 25-8-1.
//
#include "../include/queue.h"
#include <iostream>

namespace sq_queue {
    void InitQueue(Queue& q) {
        q.rear=q.front=0;
    }
    void DestroyQueue(Queue& q) {
        std::cout<<"此队列是顺序结构，不需要手动删除\n";
    }
    bool EnQueue(Queue& q,int e) {
        if ((q.rear+1)%MAX_SIZE==q.front) {
            return false;
        }
        q.data[q.rear]=e;
        q.rear=(q.rear+1)%MAX_SIZE;
        return true;
    }
    bool DeQueue(Queue& q,int& e) {
        if (QueueEmpty(q))
            return false;
        e=q.data[q.front];
        q.front=(q.front+1)%MAX_SIZE;
        return true;
    }
    bool QueueEmpty(const Queue& q) {
        return q.rear==q.front;
    }
}