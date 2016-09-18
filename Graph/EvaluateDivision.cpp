//
// Created by fengxuan on 2016/9/13.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> zeros;



    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        int size = equations.size();

        for(int i = 0; i < size; ++i) {
            if(values[i] == 0) zeros.insert(equations[i].first);
            else {
                graph[equations[i].first][equations[i].second] = values[i];
                graph[equations[i].second][equations[i].first] = 1.0/values[i];
            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
