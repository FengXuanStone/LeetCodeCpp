//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman[4][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                               "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                               "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                               "", "M", "MM", "MMM" };

        string result;

        int index = 0;
        while (num != 0) {
            int tmp = num % 10;

            string s = roman[index][tmp];
            s += result;
            result = s;

            ++index;
            num = num / 10;
        }

        return result;
    }

    string intToRoman1(int num) {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40,  10, 9, 5, 4, 1};

        string result;

        for(int i = 0; num != 0; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += roman[i];
            }
        }

        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
