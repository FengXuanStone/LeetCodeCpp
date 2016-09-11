//
// Created by fengxuan on 2016/9/10.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include<functional>
#include<thread>
#include<future>
#include<utility>
#include<stdio.h>
#include<chrono>
#include<atomic>
#include<pthread.h>

using namespace std;

atomic<int> flag(0); //采用原子操作保护g_Flag的读写

void work1(future<int> fut) {
    printf("this is thread1\n");
    flag = 1;
    fut.get(); //线程1阻塞至线程2设置共享状态
    printf("thread1 exit\n");
}

void work2(promise<int> prom) {
    printf("this is thread2\n");  //C++11的线程输出cout没有boost的好，还是会出现乱序，所以采用printf，有点不爽
    flag=2;
    prom.set_value(10);  //线程2设置了共享状态后，线程1才会被唤醒
    printf("thread2 exit\n");
}

int main() {
    cout << "Hello world" << endl;

    promise<int> prom;
    future<int> fut = prom.get_future();
    thread one(work1, move(fut));
    thread two(work2, move(prom));
    while(flag.load()==0);
    one.detach();
    two.detach();
    pthread_exit(NULL);//主线程到这里退出
    printf("main thread exit\n");

    return 0;
}
