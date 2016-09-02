//
// Created by fengxuan on 2016/9/1.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int cache;
    bool hasPeeked;
    PeekingIterator(const vector<int>& nums) : Iterator(nums), hasPeeked(false) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(hasPeeked) {
            return cache;
        } else {
            hasPeeked = true;
            return cache = Iterator::next();
        }
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(hasPeeked) {
            hasPeeked = false;
            return cache;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        if(hasPeeked) {
            return true;
        } else return Iterator::hasNext();
    }
};


int main() {
    cout << "Hello world" << endl;

    return 0;
}
