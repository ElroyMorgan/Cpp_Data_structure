//
// Created by elroy on 25-7-25.
//
#include "../include/list.h"

namespace SqList {
    void InitList(SqList& L) {
        L.length = 0;
    }

    Result ListInsert(SqList& L, const int i, const ElemType e) {
        if (i < 1 || i > L.length + 1) {
            return Result::BIT_ORDER_ERROR;
        }
        if (L.length >= MAX_SIZE) {
            return Result::FULL;
        }
        for (int j = L.length; j >= i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = e;
        ++L.length;
        return Result::OK;
    }

    bool ListDelete(SqList& L, int i, ElemType& e) {
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

    int LocateElem(const SqList& L, const ElemType e) {
        constexpr int i = 0;
        while (i < L.length) {
            if (L.data[i] == e)
                return i + 1;
        }
        return -1;
    }

    bool Del_Min(SqList& L, ElemType& e) {
        if (L.length==0) {
            return false;
        }
        int pos{0};
        ElemType del{L.data[pos]};
        for (int i=1;i<L.length;i++){
            if (del>L.data[pos]) {
                del=L.data[pos];
                pos=i;
            }
        }
        e=del;
        L.data[pos]=L.data[L.length-1];
        L.length--;
        return true;
    }
    void Reverse(SqList& L) {
        ElemType temp{};
        for (int i{0};i<L.length/2;i++) {
            temp=L.data[i];
            L.data[i]=L.data[L.length-1-i];
            L.data[L.length-1-i]=temp;
        }
    }
    void del_all_x(SqList& L,const int x) {
        int k=0;
        for (int i = 0;i<L.length;i++) {
            if (L.data[i]!=x) {
                L.data[k]=L.data[i];
                k++;
            }
        }
        L.length=k;
    }

    bool del_s_to_t(SqList& L,int s,int t) {
        // if (L.length==0 && s>=t)
        //     return false;
        // int k=0;
        // for (int i=0;i<L.length;i++) {
        //     if (L.data[i]<s ||L.data[i] >t) {
        //         L.data[k]=L.data[i];
        //         k++;
        //     }
        // }
        // L.length=k;
        // return true;

        int k=0;
        if (L.length==0 && s>=t) {
            return false;
        }
        for (int i=0;i<L.length;i++) {
            if (L.data[i]>=s && L.data[i]<=t)
                k++;
            else
                L.data[i-k]=L.data[i];
        }
        L.length -= k;
        return true;
    }


}

namespace SeqList {
    void InitList(SeqList& L) {
        L.data = new ElemType[INIT_SIZE];
        L.length = 0;
        L.MaxSize = INIT_SIZE;
    }

    void IncreaseSize(SeqList& L, const int len) {
        const ElemType* p = L.data;
        L.data = new ElemType[L.MaxSize + len];
        for (int i{0}; i < L.length + len; i++) {
            L.data[i] = p[i];
        }
        L.MaxSize += len;
        delete[] p;
    }
}

namespace LinkList {
    void InitList(LinkList& L) {
        L = new(std::nothrow) Node;
        L->next = nullptr;
    }

    void DestroyList(LinkList& L) {
        while (L) {
            const Node* p = L;
            L = L->next;
            delete p;
        }
    }

    bool ListInsert(LinkList& L, const int i, const ElemType e) {
        //1.判断i的合法性和是否空链
        if (i < 1 || L == nullptr)
            return false;
        int count{};
        Node* p = L;
        //2.找到第i-1个结点；存在边界检查：i>链表长度时定位到最后一个节点
        while (count < i - 1 && p->next != nullptr) {
            p = p->next;
            count++;
        }
        const auto s = new(std::nothrow) Node;
        if (s == nullptr)
            return false;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }

    bool ListDelete(LinkList& L, const int i, ElemType& e) {
        if (i < 1 || L == nullptr) {
            return false;
        }
        int count{};
        auto p = L;
        while (count < i - 1) {
            if (p->next == nullptr) {
                return false;
            }
            p = p->next;
            ++count;
        }
        const auto s{p->next};
        e = s->data;
        p->next = s->next;
        delete s;
        return true;
    }

    int LocateElem(const LinkList& L, const ElemType e) {
        auto s = L->next;
        int count{1};
        while (s != nullptr) {
            if (s->data == e)
                return count;
            s = s->next;
            ++count;
        }
        return -1;
    }

    void ListInsertFront(Node* L, const ElemType e) {
        if (L == nullptr)
            return;
        const auto s=new(std::nothrow) Node;
        if (s==nullptr)
            return;
        s->next=L->next;
        L->next=s;
        s->data=L->data;
        L->data=e;
    }

    void ListInsertNext(Node* L, const ElemType e) {
        if (L == nullptr)
            return;
        const auto s=new(std::nothrow) Node;
        if (s==nullptr)
            return;
        s->next=L->next;
        L->next=s;
        s->data=e;
    }
}
