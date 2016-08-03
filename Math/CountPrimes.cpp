//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0)
            return 0;

        bool candidate[n - 1];
        memset(candidate, false, sizeof(candidate));

        candidate[0] = true;
        int count = 0, limit = (int)sqrt(n);

        for(int i = 2; i <= limit; ++i) {
            if(!candidate[i - 1]) {
                for(int j = i * i; j < n; j += i) {
                    candidate[j - 1] = true;
                }
            }
        }

        for(int i = 0; i < n - 1; ++i) {
            if(!candidate[i]) ++count;
        }

        return count;
    }
};


int main() {
    cout << "Hello world" << endl;

    return 0;
}
