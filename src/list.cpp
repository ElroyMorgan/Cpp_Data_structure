//
// Created by elroy on 25-7-25.
//
#include "../include/list.h"

namespace SqList {
    void InitList(SqList &L) {
        L.data = {0};
        L.length = 0;
    }

    Result ListInsert(SqList &L, const int i, const ElemType e) {
        if (i < 1 || i > L.length + 1) {
            return Result::BIT_ORDER_ERROR;
        }
        if (L.length >= MAX_SIZE) {
            return Result::FULL;
        }
        for (int j = L.length; j >=

                               i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = e;
        ++L.length;
        return Result::OK;
    }

    bool ListDelete(SqList &L, int i, ElemType &e) {
        if (i < 1 || i > L.length + 1) {
            return false;
        }
        e = L.data[i - 1];
        for (int j = i; j < L.length; j++) {
            L.data[j - 1] = L.data[j];
        }
        --L.length;
        return true;
    }

    int LocateElem(const SqList &L, const ElemType e) {
        constexpr int i = 0;
        while (i < L.length) {
            if (L.data[i] == e)
                return i + 1;
        }
        return -1;
    }
}

namespace SeqList {
    void InitList(SeqList &L) {
        L.data = new ElemType[INIT_SIZE];
        L.length = 0;
        L.MaxSize = INIT_SIZE;
    }

    void IncreaseSize(SeqList &L, int len) {
        const ElemType *p = L.data;
        L.data = new ElemType[L.MaxSize + len];
        for (int i{0}; i < L.length + len; i++) {
            L.data[i] = p[i];
        }
        L.MaxSize += len;
        delete[] p;
    }
}
