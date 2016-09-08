//
// Created by fengxuan on 2016/9/4.
//
#include <assert.h>
#include <ostream>
#include "SeqStack.h"

using namespace std;

template <class T>
ostream& operator << (ostream& os, SeqStack<T>& s) {
    os << "top = " << s.top << endl;

    for(int i = 0; i <= s.top; ++i) {
        os << i << ": " << s.element[i] << endl;
    }

    return os;
}

template <class T>
SeqStack<T>::SeqStack(int sz):top(-1), maxSize(sz) {
    element = new T[maxSize];
    assert(element != NULL);
}