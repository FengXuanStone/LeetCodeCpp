//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    const int base = 1337;
    int pow(int a, int k) {
        a %= base;
        int result = 1;
        for(int i = 0; i < k; ++i) {
            result = (result * a) % base;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        return pow(superPow(a, b), 10) * pow(a, last) % base;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
