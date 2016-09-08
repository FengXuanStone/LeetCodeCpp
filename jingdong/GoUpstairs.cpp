//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class GoUpstairs {
public:
    int countWays(int n) {
        // write code here
        if(n <= 1) return 0;
        if(n == 2) return 1;

        int first = 1, second = 2;

        for(int i = 2; i < n; ++i) {
            second = second + first;
            first = second - first;
            if(second > 1000000007){
                first %= 1000000007;
                second %= 1000000007;
            }
        }

        return first;
    }
};

int main() {
    cout << "Hello world" << endl;

    GoUpstairs* ss = new GoUpstairs;
    cout << ss->countWays(96) << endl;

    return 0;
}
