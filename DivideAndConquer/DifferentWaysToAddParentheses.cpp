//
// Created by fengxuan on 2016/8/29.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;

        for(int i = 0; i < input.size(); ++i) {
            char x = input[i];
            if(ispunct(x)) {
                for(int a : diffWaysToCompute(input.substr(0, i))) {
                    for(int b : diffWaysToCompute(input.substr(i + 1)))
                        result.push_back( x == '+' ? a + b : x == '-' ? a - b : a * b );
                }
            }
        }

        return result.size() ? result : vector<int>{stoi(input)};
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
