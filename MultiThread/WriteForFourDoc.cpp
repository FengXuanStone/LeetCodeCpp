//
// Created by fengxuan on 2016/9/10.
//
#include <iostream>
#include <algorithm>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cond;
int flag = 0;

void func(int num) {
    for(int i = 0; i < 10; ++i) {
        unique_lock<mutex> ul(m);

        while(flag != num)
            cond.wait(ul);

        cout << num + 1 << " ";

        flag = (flag + 1) % 4;
        cond.notify_all();
    }
}

int main() {
    cout << "Hello world" << endl;

    for(int i= 0; i < 4; ++i) {
        cout << (char)(i + 'A') << ": ";

        flag = i;

        thread t1(func, 1);
        thread t2(func, 2);
        thread t3(func, 3);
        func(0);

        t1.join();
        t2.join();
        t3.join();

        cout << endl;
    }
    return 0;
}
