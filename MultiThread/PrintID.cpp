//
// Created by fengxuan on 2016/9/10.
//
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>

//题目：编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推。
using namespace std;

mutex m;
condition_variable cond;
int flag = 0;

void func(int ID) {
    for(int i = 0; i < 10; ++i) {
        unique_lock<mutex> ul(m);

        while (flag != ID)
            cond.wait(ul);

        cout << (char)('A' + ID) << endl;

        flag = (flag + 1) % 3;
        cond.notify_all();
    }
}


int main() {
    cout << "Hello world" << endl;

    thread t1(func, 0);
    thread t2(func, 1);
    func(2);
    t1.join();
    t2.join();

    return 0;
}
