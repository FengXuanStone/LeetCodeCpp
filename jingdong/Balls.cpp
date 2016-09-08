//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Balls {
public:
    int calcDistance(int A, int B, int C, int D) {
        // write code here
        double count = A + B + C + D;
        double result = 0;

        while (count> 0.000001) {
            result += count;
            count = count / 2;
            result += count;
        }

        return (int)(result + 0.5);
    }
};

int main() {
    cout << "Hello world" << endl;

    Balls* ss = new Balls;
    cout << ss->calcDistance(100, 90, 80, 70) << endl;


    return 0;
}
