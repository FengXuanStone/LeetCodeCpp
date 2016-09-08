//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Apples {
public:
    int getInitial(int n) {
        // write code here
        int sum = (int)(pow(n , n) - n + 1);
        return sum;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
