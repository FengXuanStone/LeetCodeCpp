//
// Created by fengxuan on 2016/9/4.
//

#ifndef LEETCODECPP_QUEUE_H
#define LEETCODECPP_QUEUE_H

#endif //LEETCODECPP_QUEUE_H
const int maxSize = 50;

template <class T>
class Queue {
public:
    Queue() { };
    ~Queue() { };
    virtual void EnQueue(const T& x) = 0;
    virtual bool DeQueue(const T& x) = 0;
    virtual bool getFront(T& x) = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual int getSize() const = 0;
};