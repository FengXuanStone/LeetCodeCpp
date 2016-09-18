//
// Created by fengxuan on 2016/9/14.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include "myString.h"

using namespace std;

myString::myString() {
    this->m_data = new char[1];
    *m_data = '\0';
};
myString::myString(const char* pr) {
    if(NULL == pr) {
        this->m_data = new char[1]; // 得分点：对空字符串自动申请存放结束标志'\0'的    //加分点：对m_data加NULL 判断
        *m_data = '\0';
    } else {
        int len = strlen(pr);
        this->m_data = new char[len + 1]; // 若能加 NULL 判断则更好
        strcpy(m_data, pr);
    }
};
myString::myString(const myString& rhs) { // 得分点：输入参数为const型
    int len = strlen(rhs.m_data);
    this->m_data = new char[len + 1]; //加分点：对m_data加NULL 判断
    strcpy(this->m_data, rhs.m_data);
};
myString myString::operator=(const myString& rhs) { // 得分点：输入参数为const
    if(this != rhs) {                //得分点：检查自赋值
        delete[] m_data;            //得分点：释放原有的内存资源
        m_data = new char[strlen(rhs.m_data) + 1]; //加分点：对m_data加NULL 判断
        strcpy(this->m_data, rhs);
    }
    return *this;                  //得分点：返回本对象的引用
};
myString::~myString() {
    delete[] m_data;
};
myString myString::operator+(const myString& rhs) {
    myString newMyString;
    if(!rhs.m_data) newMyString = *this;
    else if(!m_data) newMyString = rhs;
    else {
        newMyString.m_data = new char[strlen(m_data), strlen(rhs.m_data) + 1];
        strcpy(newMyString.m_data, m_data);
        strcat(newMyString.m_data, rhs.m_data);
    }

    return newMyString;
};
char myString::operator[](const unsigned int index) {
    return m_data[index];
};
bool myString::operator==(const myString& rhs) {
    int result = strcmp(m_data, rhs.m_data);
    return 0 == result;
};
ostream& operator<<(ostream& output, const myString& rhs) {
    output << m_data;
    return output;
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
