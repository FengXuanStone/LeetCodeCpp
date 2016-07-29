//
// Created by fengxuan on 2016/7/29.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num == 0)
            return false;

        int result = num;

        while (result != 1) {
            if(result % 2 == 0) result = result / 2;
            else if(result % 3 == 0) result = result / 3;
            else if(result % 5 == 0) result = result / 5;
            else return false;
        }

        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
