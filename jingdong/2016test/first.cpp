//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <iomanip>

using namespace std;



int main() {
    int a;

    while (cin >> a) {
        if(a <= 2) {
            cout <<  "0/0" << endl;
            continue;
        }

        int result = 0;

        for(int i = 2; i < a; ++i) {
            int tmp = a;
            while (tmp) {
                result += (tmp % i);
                tmp = tmp / i;
            }
        }

        int k = a- 2;
        for(int i = k; i >= 2; --i) {
            if(result % i == 0 && k % i == 0) {
                result = result / i;
                k = k / i;
            }
        }

        cout << result << '/' << k << endl;
    }

    return 0;
}
