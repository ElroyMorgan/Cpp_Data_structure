#include <iostream>
#include "../include/stack.h"
#include "../include/queue.h"
void test_stack_link();
void test_queue();

int main() {
    return 0;
}

void test_stack_link() {
    // 测试栈功能
    std::cout << "\n--- 测试栈功能 ---" << std::endl;
    stack::Stack stack;

    // 测试push操作
    std::cout << "压入元素: 10, 20, 30" << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // 测试pop操作
    std::cout << "弹出元素: " << stack.pop() << std::endl;
    std::cout << "弹出元素: " << stack.pop() << std::endl;
    std::cout << "弹出元素: " << stack.pop() << std::endl;

    // 再次压入并弹出
    std::cout << "压入元素: 40, 50" << std::endl;
    stack.push(40);
    stack.push(50);
    std::cout << "弹出元素: " << stack.pop() << std::endl;
    std::cout << "弹出元素: " << stack.pop() << std::endl;
}

void test_queue() {
    // 测试队列功能
    std::cout << "\n--- 测试队列功能 ---" << std::endl;
    sq_queue::Queue queue;
    
    // 初始化队列
    sq_queue::InitQueue(queue);
    
    // 测试入队操作
    std::cout << "入队元素: 10, 20, 30" << std::endl;
    sq_queue::EnQueue(queue, 10);
    sq_queue::EnQueue(queue, 20);
    sq_queue::EnQueue(queue, 30);
    
    // 测试出队操作
    int e;
    sq_queue::DeQueue(queue, e);
    std::cout << "出队元素: " << e << std::endl;
    sq_queue::DeQueue(queue, e);
    std::cout << "出队元素: " << e << std::endl;
    
    // 再次入队并出队
    std::cout << "入队元素: 40, 50" << std::endl;
    sq_queue::EnQueue(queue, 40);
    sq_queue::EnQueue(queue, 50);
    sq_queue::DeQueue(queue, e);
    std::cout << "出队元素: " << e << std::endl;
    sq_queue::DeQueue(queue, e);
    std::cout << "出队元素: " << e << std::endl;
}