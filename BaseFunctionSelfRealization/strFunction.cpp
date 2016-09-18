//
// Created by fengxuan on 2016/9/14.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

char *myStrcat(char *dest, const char *src) {
    char *addr = dest;
    while (*dest) { //找到'\0'
        dest++;
    }
    while (*dest = *src ) {
        dest++;
        src++;
    };

    return addr;
}

int myStrcmp(const char* str1, const char* str2) {
    while (*str1 == *str2) {
        if('\0' == *str1)
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *strcpy(char *dest, const char* src) {
    char *attr = dest;
    while (*dest++ = * src++) { }
    return attr;
}

unsigned int strlen(const char* str) const {
    unsigned len = 0;
    while ('\0' != *str) {
        len++;
        str++;
    }

    return len;
}

char *strchr(char *str, char c) {
    while('\0' != *str && c != *str) {
        str++;
    }

    return (c == *str ? str : NULL);
}

char *strrchr(char *str, char c) {
    char *p = str + strlen(str);
    while (p != str && *p != c) {
        p--;
    }

    if(p == str && *p != c) return NULL;
    else return p;
}

int strCspn(const char* pStr, const char* pStrSet) {
    // map有32个字节的大小，也就是256个bit，可把map堪称一个2维数组[32][8]
    unsigned char map[32] = {0};

    // 每个ASCII码(设为c)有8bit，把它分成2部分，低3位构成下标j(通过c&7(2进制为111)),
    // 高5位构成下标i(通过c>>3得到)。这样在map[i][j]中置1表示字符存在

    while (&pStrSet ) {
        map[*pStrSet  >> 3] |= (1 << (*pStrSet  & 7));
        pStrSet++;
    }

    map[0] != 1;

    int count = 0;
    while(!(map[*pStr >> 3] & (1 << (*pStr & 7))))
    {
        count++;
        pStr++;
    }

    return count;
}

char *strdup(const char *str) {
    char *p = NULL;

    if(str && (p = (char*)malloc(strlen(str) + 1)))
        strcpy(p, str);

    return p;
}

char *strrev(char *str) {
    if(NULL == str)
        return NULL;

    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

char *strstr(char *str1, const char *str2)
{
    int length1=strlen(str1);
    int length2=strlen(str2);
    while(length1>=length2)
    {
        length1--;
        if(!strncpy(str1,str2,length2))//比较前n个字符串，类似strcpy
            return str1;
        str1++;
    }
    return NULL;
}


int main() {
    cout << "Hello world" << endl;

    char a[] = {'a','b','c','d','e','f','g'};
    char b[] = {'h','i','j','k','l','m','n'};

    char *c = myStrcat(a, b);
    char *d = strcat(a, b);

    printf("%s", c);


    return 0;
}
