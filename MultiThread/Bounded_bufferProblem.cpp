//
// Created by fengxuan on 2016/9/10.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <thread>
#include <condition_variable>
#include <queue>
#include <assert.h>

using namespace std;

mutex m;
condition_variable full, empty;
queue<int> Q;   // 缓冲区大小为10,缓冲区数据为int，这里充当blocking queue
bool flag = true;    //一个简陋的设计，当不再生产时采用flag终止消费者线程

void put(int num) {
    for(int i = 0; i < num; ++i) {
        unique_lock<mutex> ul(m);

        while (Q.size() > 10)
            full.wait(ul);

        assert(Q.size() < 10);
        Q.push(i);

        cout << "生产 " << i << endl;
        empty.notify_all();
    }

    flag = false;
}

void take() {
    while (flag) {
        unique_lock<mutex> ul(m);

        while (Q.empty())
            empty.wait(ul);

        if(flag) {
            assert(!Q.empty());
            cout << "消费 " << Q.front() << endl;
            Q.pop();
            full.notify_all();
        }
    }
}

int main() {
    cout << "Hello world" << endl;

    thread t1(take);
    thread t2(take);
    thread t3(take);
    put(10);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
