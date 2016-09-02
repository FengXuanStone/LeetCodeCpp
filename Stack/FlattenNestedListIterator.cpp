//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> begin, end;

    NestedIterator(vector<NestedInteger> &nestedList) {
        begin.push(nestedList.begin());
        end.push(nestedList.end());
    }

    int next() {
        return (begin.top()++)->getInteger();
    }

    bool hasNext() {
        while (begin.size()) {
            if(begin.top() == end.top()) {
                begin.pop();
                end.pop();
            } else {
                auto val = begin.top();
                if(val->isInteger()) return true;
                begin.top()++;
                begin.push(val->getList().begin());
                end.push(val->getList().end());
            }
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
