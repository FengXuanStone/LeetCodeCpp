//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <map>
#include<sstream>
#include <memory.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        map<char, int > secMap;
        for(int i = 0; i < secret.size(); ++i) {
            char tmp = secret[i];
            char tmp2 = guess[i];

            if(tmp == tmp2) {
                ++bulls;
            } else {
                if(secMap.find(tmp) == secMap.end()) {
                    secMap.insert(pair<char, int >(tmp, 0));
                }
                secMap[tmp] = secMap[tmp] + 1;
            }
        }

        for(int i = 0; i < secret.size(); ++i) {
            char tmp = secret[i];
            char tmp2 = guess[i];

            if(tmp != tmp2 && secMap.find(tmp2) != secMap.end()) {
                if(secMap[tmp2] > 0) {
                    ++cows;
                    secMap[tmp2] = secMap[tmp2] - 1;
                }
            }
        }

        ostringstream oss;
        oss << bulls << 'A' << cows << 'B';
        string s = oss.str();

        return s;
    }

    string getHint1(string secret, string guess) {
        int countA = 0;
        int countB = 0;
        int count[10];

        memset(count,0, sizeof(count));

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                countA++;
            } else {
                count[secret[i] - '0']++;
                if (count[secret[i] - '0'] <= 0) {
                    countB++;
                }
                count[guess[i] - '0']--;
                if (count[guess[i] - '0'] >= 0) {
                    countB++;
                }
            }
        }

        ostringstream oss;
        oss << countA << 'A' << countB << 'B';
        string s = oss.str();

        return s;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->getHint1("12","23") << endl;

    return 0;
}
