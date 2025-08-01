//
// Created by elroy on 25-8-1.
//

#ifndef QUEUE_H
#define QUEUE_H

namespace sq_queue {
#define MAX_SIZE 10
    typedef struct Queue{
        int data[MAX_SIZE];
        int rear,front;
    }Queue;
    void InitQueue(Queue& q);
    void DestroyQueue(Queue& q);
    bool EnQueue(Queue& q,int e);
    bool DeQueue(Queue& q,int& e);
    bool QueueEmpty(const Queue& q);
}


#endif //QUEUE_H