//
// Created by fengxuan on 2016/9/22.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

enum some_big_cities {
     id,
     name,
     type,
     age,
     yuwen,
     maths,
     english,
     computer,
     count,
};

struct Item {
    int id;
    string name;
    string type;
    int age;
    int yuwen;
    int maths;
    int english;
    int computer;
    int count;
};

bool idMark(const Item& lit, const Item& rit) {
    return lit.id < rit.id;
}
bool ageMark(const Item& lit, const Item& rit) {
    return lit.age < rit.age;
}
bool yuwenMark(const Item& lit, const Item& rit) {
    return lit.yuwen < rit.yuwen;
}
bool mathsMark(const Item& lit, const Item& rit) {
    return lit.maths < rit.maths;
}
bool englishMark(const Item& lit, const Item& rit) {
    return lit.english < rit.english;
}
bool computerMark(const Item& lit, const Item& rit) {
    return lit.computer < rit.computer;
}
bool countMark(const Item& lit, const Item& rit) {
    return lit.count < rit.count;
}

int main() {
    cout << "Hello world" << endl;

    vector<Item> stItemVec;
    stack<string> candidate;
    string s;
    string buf;
    stringstream ss(s);
    cin >> s;

    while (ss >> buf)
        candidate.push(buf);

    cin >> s;
    cout << s;

    while(cin >> s) {
        string buf1;
        stringstream ss1(s);
        Item stItem1;
        if(ss >> buf1) {
            stItem1.id = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.name = buf1;
        }
        if(ss >> buf1) {
            stItem1.type = buf1;
        }
        if(ss >> buf1) {
            stItem1.age = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.yuwen = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.maths = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.english = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.computer = stoi(buf1);
        }
        if(ss >> buf1) {
            stItem1.count = stoi(buf1);
        }
        stItemVec.push_back(stItem1);
    }




    return 0;
}
