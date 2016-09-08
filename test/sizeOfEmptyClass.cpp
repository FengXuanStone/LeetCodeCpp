//
// Created by fengxuan on 2016/9/8.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class A {
    int a;
};

class B {
    int b;
};

class C : public A, public B {
    int c;
};

class D :public virtual A {

};

int main() {
    cout << "Hello world" << endl;

    C c;
    A* pa = &c;
    B* pb = &c;

    cout << &c << endl;
    cout << pa << endl;
    cout << pb << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(D) << endl;

    return 0;
}
