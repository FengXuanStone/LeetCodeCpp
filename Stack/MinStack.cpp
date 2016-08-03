//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MinStack {
    stack<int> cur;
    stack<int> min;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(cur.empty()) {
            cur.push(x);
            min.push(x);
        } else {
            cur.push(x);
            if(x > min.top()) {
                min.push(min.top());
            } else min.push(x);
        }
    }

    void pop() {
        cur.pop();
        min.pop();
    }

    int top() {
        return cur.top();
    }

    int getMin() {
        return min.top();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
