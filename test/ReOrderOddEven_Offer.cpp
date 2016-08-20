//
// Created by fengxuan on 2016/8/14.
//
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
    if(pData == NULL || length == NULL) return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while (pBegin < pEnd) {
        while (pBegin < pEnd && !func(*pBegin)) pBegin++;

        while (pBegin < pEnd && func(*pEnd)) pEnd--;

        if(pBegin < pEnd) {
            int tmp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = tmp;
        }
    }
}

bool isEven(int n) {
    return (n & 1) == 0;
}

void ReorderOddEven(int *pData, unsigned int length) {
    Reorder(pData, length, isEven);
}

int main() {
    unsigned a = 10;


    cout << "Hello world" << endl;

    vector<int> vec;
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;

//    while (in_iter != eof) {
//        vec.push_back(*in_iter++);
//    }

   cout << accumulate(in_iter, eof, 0) << endl;

    return 0;
}
