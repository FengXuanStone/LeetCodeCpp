//
// Created by fengxuan on 2016/8/6.
//
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;

        return (int)sqrt(n);
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
