//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;

        for(int i = 0; i <= num; ++i) {
            result.push_back(count(i));
        }

        return result;
    }

    int count(int num) {
        int bits = 0;

        while (num > 0) {
            if((num & 1) == 1) ++bits;
            num >>= 1;
        }

        return bits;
    }

    vector<int> countBits1(int num) {
        vector<int> result(num + 1);

        for(int i = 0; i <= num; ++i) {
            if(i % 2 == 0) {
                result[i] = result[i / 2];
            } else result[i] = result[i / 2] + 1;
        }

        return result;
    }

};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
