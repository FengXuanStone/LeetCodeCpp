//
// Created by fengxuan on 2016/9/10.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <thread>
#include <mutex>
#include <condition_variable>

//题目：子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码。
using namespace std;

mutex m;
condition_variable cond;
int flag = 5;

void func(int num) {
    for(int i = 0; i < 50; ++i) {
        unique_lock<mutex> ul(m);

        while (flag != num)
            cond.wait(ul);

        for(int j = 0; j < num; ++j)
            cout << j << ' ';
        cout << endl;

        flag = (num == 5) ? 10 : 5;

        cond.notify_one();
    }
}

int main() {
    cout << "Hello world" << endl;
    thread t(func, 5);
    func(10);
    t.join();

    return 0;
}
