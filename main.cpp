//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

struct Node{
    int count;
    char a;
};

bool compare(Node &a, Node &b) {
    return a.count > b.count;
}

struct NodeCompare{
    bool operator() (const Node& a, const Node& b) {
        return a.count < b.count;
    }
};

int main() {
    cout << "Hello world" << endl;

    set<Node, NodeCompare> ss;


    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;

        vector<int> candidate;
        int tmp = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ',') {
                candidate.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp * 10 + (s[i] - '0');
            }
        }
    }



    return 0;
}
