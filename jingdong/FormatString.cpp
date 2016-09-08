//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

void FormatString(char str[],int len){
    if(len <= 0) return;

    int i = 0;

    for(int j = 0; j < len; ++j) {
        if(str[j] == ' ') {
            if(i == 0 || str[i - 1] == ' ') continue;
            else str[i++] = str[j];
        } else {
            str[i++] = str[j];
        }
    }
    if(str[i - 1] == ' ') str[i - 1] = '\0';
}

int main() {
    cout << "Hello world" << endl;

    char ch[] = "   i    am a      little boy.    ";
    FormatString(ch, 33);

    for(int i = 0; ch[i] != '\0'; ++i) {
        cout << ch[i];
    }
    cout << endl;

    return 0;
}
