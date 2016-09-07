//
// Created by fengxuan on 2016/9/6.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <stack>

using namespace std;

class NestedInteger {
     public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    stack<NestedInteger* > candidate;
public:
    NestedInteger deserialize(string s) {
        NestedInteger *cur;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ',') continue;
            cur = new NestedInteger;
            if(s[i] == '[') candidate.push(new NestedInteger());
            else if(s[i] == ']') {
                cur = candidate.top();
                candidate.pop();
                if(!candidate.empty()) candidate.top()->add(*cur);
            } else {
                int j = i;
                while(j < s.size() && s[j] != ',' && s[j] != ']') ++j;
                cur->setInteger(stoi(s.substr(i, j - i)));
                if(!candidate.empty()) candidate.top()->add(*cur);
                i = j - 1;
            }
        }

        return candidate.empty() ? *cur : *candidate.top();
    }
};

int main() {
    cout << "Hello world" << endl;

    string s = "[[]]";
    Solution* ss = new Solution;
    ss->deserialize(s);

    return 0;
}
