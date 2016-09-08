//
// Created by fengxuan on 2016/9/4.
//

#ifndef LEETCODECPP_SEQSTACK_H
#define LEETCODECPP_SEQSTACK_H

#endif //LEETCODECPP_SEQSTACK_H

#include <assert.h>
#include <iostream>
#include <ostream>
const int stackIncreament = 20;

template <class T>
class SeqStack {
public:
    SeqStack(int sz = 50);
    ~SeqStack() { delete[] element; }
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x);
    bool IsEmpty() const { return top == -1; }
    bool IsFull() const { return top == maxSize - 1; }
    int getSize() const { return top + 1; }
    void MakeEmpty() { top = -1; }
    friend std::ostream& operator << (std::ostream& os, SeqStack<T>& s);
private:
    T *element;
    int top;
    int maxSize;
    void overflowProcess();
};

