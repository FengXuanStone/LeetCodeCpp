//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() - 1;
        int i = 0;

        while (n >= 0) {
            if(citations[n] > i) {
                ++i;
                --n;
            } else break;
        }
        return i;
    }

    int hIndex1(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int tmp = n - mid;
            if(citations[mid] == tmp) return tmp;
            else if(citations[mid] < tmp) left = mid + 1;
            else right = mid - 1;
        }

        return n - left;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
