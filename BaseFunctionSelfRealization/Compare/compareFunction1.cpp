//
// Created by fengxuan on 2016/9/14.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

struct TItem {
    int id;
    int type;

    bool operator <(const TItem& rhs) const {  //升序排序时必须写的函数
        return type < rhs.type;
    }

    bool operator >(const TItem& ths) const { // 降序排序时必须写的函数
        return type > ths.type;
    }

};

int main() {
    cout << "Hello world" << endl;

    vector<TItem> stItemVec;


    TItem stItem1;
    stItem1.type = 1;
    stItem1.id = 1;

    TItem stItem2;
    stItem2.type = 2;
    stItem2.id = 2;

    TItem stItem3;
    stItem3.type = 3;
    stItem3.id = 3;

    TItem stItem4;
    stItem4.type = 2;
    stItem4.id = 4;

    stItemVec.push_back(stItem1);
    stItemVec.push_back(stItem2);
    stItemVec.push_back(stItem3);
    stItemVec.push_back(stItem4);

    // 升序排序
    sort(stItemVec.begin(), stItemVec.end(), less<TItem>());
    // 或者sort(stItemVec.begin(), stItemVec.end());   默认情况为升序

    for (size_t i = 0; i < stItemVec.size(); i++)
        printf("type: %d, id: %d\n", stItemVec[i].type, stItemVec[i].id);

    //降序排序
    sort(stItemVec.begin(), stItemVec.end(), greater<TItem>());

    for (size_t i = 0; i < stItemVec.size(); i++)
        printf("type: %d, id: %d\n", stItemVec[i].type, stItemVec[i].id);


    return 0;
}
