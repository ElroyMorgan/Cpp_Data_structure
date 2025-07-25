//
// Created by elroy on 25-7-25.
//

#ifndef LIST_H
#define LIST_H
//静态分配顺序表
using ElemType = int;
constexpr int MAX_SIZE = 100;

namespace SqList {
    typedef struct {
        ElemType data[MAX_SIZE]{};
        int length{};
    } SqList;

    //初始化
    void InitList(SqList &L);

    //按位序插入
    bool ListInsert(SqList &L, int i, ElemType e);

    //按位序删除
    bool ListDelete(SqList &L, int i, ElemType &e);

    //按值查找
    int LocateElem(SqList &L, ElemType e);
}

//动态分配顺序表
namespace SeqList {
    typedef struct {
        ElemType *data{};
        int MaxSize{}, length{};
    } SeqList;

    void InitList(SeqList &L);
}

#endif //LIST_H
