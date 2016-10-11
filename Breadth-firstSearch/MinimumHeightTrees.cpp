//
// Created by fengxuan on 2016/9/23.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

class TNode {
public:
    int val;
    unordered_set<TNode* > neighbors;

    TNode(int i): val(i) { }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        map<int, TNode* > val_node;
        //create vertexs
        for(int i = 0; i < n; ++i) {
            TNode* tmp = new TNode(i);
            val_node[i] = tmp;
        }
        //create edges
        for(int i = 0; i < edges.size(); ++i) {
            pair<int, int> pp = edges[i];
            val_node[pp.first]->neighbors.insert(val_node[pp.second]);
            val_node[pp.second]->neighbors.insert(val_node[pp.first]);
        }

        map<int, TNode*>::iterator m_iter;

        while (val_node.size() > 2) {
            // obtain all leaves in current graph;
            list<TNode* > listg;

            for(m_iter = val_node.begin(); m_iter != val_node.end(); m_iter++) {
                if(m_iter->second->neighbors.size() == 1)
                    listg.push_back(m_iter->second);
            }

            // remove all leaves
        }

    }
};

int main() {
    cout << "Hello world" << endl;



    return 0;
}
