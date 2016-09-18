//
// Created by fengxuan on 2016/9/14.
//

#ifndef LEETCODECPP_MYSTRING_H
#define LEETCODECPP_MYSTRING_H

#endif //LEETCODECPP_MYSTRING_H

#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

class myString{
private:
    char *m_data;
public:
    myString();
    myString(const char* pr);
    myString(const myString& rhs);
    myString operator=(const myString& rhs);
    ~myString();
    myString operator+(const myString& rhs);
    char operator[](const unsigned int index);
    bool operator==(const myString& rhs);
    friend ostream& operator<<(ostream& output, const myString& rhs);
};