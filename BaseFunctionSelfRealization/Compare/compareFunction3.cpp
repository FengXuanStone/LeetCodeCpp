//
// Created by fengxuan on 2016/9/23.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

struct Item {
    int type;
    int id;
};

class ComLess {
public:
    bool operator() (const Item& lit, const Item& rit) {
        return lit.type < rit.type;
    }
};

class Comgreater {
public:
    bool operator() (const Item& lit, const Item& rit) {
        return lit.type > rit.type;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<Item> stItemVec;


    Item stItem1;
    stItem1.type = 1;
    stItem1.id = 1;


    Item stItem2;
    stItem2.type = 2;
    stItem2.id = 2;


    Item stItem3;
    stItem3.type = 3;
    stItem3.id = 3;


    Item stItem4;
    stItem4.type = 2;
    stItem4.id = 4;

    stItemVec.push_back(stItem1);
    stItemVec.push_back(stItem2);
    stItemVec.push_back(stItem3);
    stItemVec.push_back(stItem4);

    //升序排序
    sort(stItemVec.begin(), stItemVec.end(), ComLess());

    for (size_t i = 0; i < stItemVec.size(); i++)
        printf("type: %d, id: %d\n", stItemVec[i].type, stItemVec[i].id);

    //降序排序
    sort(stItemVec.begin(), stItemVec.end(), Comgreater());

    for (size_t i = 0; i < stItemVec.size(); i++)
        printf("type: %d, id: %d\n", stItemVec[i].type, stItemVec[i].id);

    return 0;
}
