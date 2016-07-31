//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> a;
    queue<int> b;

    // Push element x onto stack.
    void push(int x) {
        if(!a.empty()) {
            b.push(x);
            while(!a.empty()) {
                int t = a.front();
                b.push(t);
                a.pop();
            }
        } else {
            a.push(x);
            while (!b.empty()) {
                int t = b.front();
                a.push(t);
                b.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!a.empty()) return a.pop();
        else return b.pop();
    }

    // Get the top element.
    int top() {
        if(!a.empty()) return a.front();
        else return b.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return a.empty() && b.empty();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
