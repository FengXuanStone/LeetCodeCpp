//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

        if(E >= A && E < C) {
            x1 = E;
            x2 = G > C ? C : G;
        } else if(E < A && A <= G) {
            x1 = A;
            x2 = G > C ? C : G;
        }

        if(F >= B && F < D) {
            y1 = F;
            y2 = H > D ? D : H;
        } else if(F < B && B <= H) {
            y1 = B;
            y2 = H > D ? D : H;
        }

        int area = (C - A) * (D - B) + (G - E) * (H - F) - (x2 - x1) * (y2 - y1);
        return area;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->computeArea(0,0,0,0,-1,-1,1,1);

    return 0;
}
