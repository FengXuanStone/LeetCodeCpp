//
// Created by fengxuan on 2016/8/1.
//
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t i = 1;

        for(; i != 0; i <<= 1) {
            result <<= 1;
            if(n & 1) {result |= 1; }
            n >>= 1;
        }

        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
