//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        vector<char> candidate1;
        vector<char> candidate2;

        while (i < version1.size() || j < version2.size()) {
            for(; i < version1.size(); ++i) {
                if(version1[i] == '.') break;
                else if(candidate1.empty() && version1[i] == '0') continue;
                else candidate1.push_back(version1[i]);
            }
            for(; j < version2.size(); ++j) {
                if(version2[j] == '.') break;
                else if(candidate2.empty() && version2[j] == '0') continue;
                else candidate2.push_back(version2[j]);
            }

            if(candidate1.size() > candidate2.size()) return 1;
            else if(candidate1.size() < candidate2.size()) return -1;
            else {
                for(int k = 0; k < candidate1.size(); ++k) {
                    if(candidate1[k] > candidate2[k]) return 1;
                    else if(candidate1[k] < candidate2[k]) return -1;
                }
            }

            ++i;
            ++j;
            candidate1.clear();
            candidate2.clear();
        }

        return 0;
    }

    int compareVersion1(string version1, string version2) {
        int i = 0, j = 0;

        while (i < version1.size() || j < version2.size()) {
            int count1 = 0, count2 = 0;

            for(; i < version1.size(); ++i) {
                if(version1[i] == '.') break;
                count1 = count1 * 10 + (version1[i] - '0');
            }
            for(; j < version2.size(); ++j) {
                if(version2[j] == '.') break;
                count2 = count2 * 10 + (version2[j] - '0');
            }

            if(count1 > count2) return 1;
            else if(count1 < count2) return -1;

            ++i;
            ++j;
        }

        return 0;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->compareVersion("1","1.1") << endl;

    return 0;
}
