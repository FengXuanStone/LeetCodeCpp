//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int > candidate;
    int tmp;

    int k = a;
    while (k) {
        cin >> tmp;
        candidate.push_back(tmp);
        --k;
    }

    int result = 0;

    for(int i = 0; i < a; ++i) {
        for(int j = i + 1; j < a; ++j) {
            if(j == i + 1) result++;
            else {
                bool flag = true;
                for(int k = i + 1; k < j;++k) {
                    if(candidate[i] <= candidate[k] || candidate[j] <= candidate[k]) {
                        flag = false;
                        break;
                    };
                }

                if(flag) {
                    result++;
                    continue;
                } else {
                    flag = true;

                    for(int k = 0; k < i; ++k) {
                        if(candidate[i] <= candidate[k] || candidate[j] <= candidate[k]) {
                            flag = false;
                            break;
                        };
                    }
                    for(int k = j + 1; k < a; ++k) {
                        if(candidate[i] <= candidate[k] || candidate[j] <= candidate[k]) {
                            flag = false;
                            break;
                        };
                    }

                    if(flag) {
                        result++;
                        continue;
                    }
                }
            }
        }
    }


    cout << result << endl;

    return 0;
}
