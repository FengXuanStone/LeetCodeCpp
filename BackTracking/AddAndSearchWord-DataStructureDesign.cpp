//
// Created by fengxuan on 2016/8/25.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class WordDictionary {
public:
    struct node {
        char ch;
        vector<node *> subTree;

        node(char c): ch(c) { };
    };

    node * root = new node('.');

    // Adds a word into the data structure.
    void addWord(string word) {
        node* cur = root;

        for(int i = 0; i < word.size(); ++i) {
            bool flag = false;

            for(auto j = cur->subTree.cbegin(); j != cur->subTree.cend(); ++j) {
                if((*j)->ch == word[i]) {
                    cur = *j;
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                node* tmp = new node(word[i]);
                cur->subTree.push_back(tmp);
                cur = tmp;
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.size() == 0) return true;

        vector<node *> candidate;
        candidate.push_back(root);
        int i = 0;
        int n = word.size();

        while (i < n && !candidate.empty()) {
            vector<node *> tmp;
            char xx = word[i];

            if(xx == '.') {
                for(int j = 0; j < candidate.size(); ++j) {
                    tmp.insert(tmp.end(),candidate[j]->subTree.begin(), candidate[j]->subTree.end());
                }
            } else {
                for(int j = 0; j < candidate.size(); ++j) {
                    for(int k = 0; k < candidate[j]->subTree.size(); ++k) {
                        node * yy = candidate[j]->subTree[k];

                        if(xx == yy->ch) {
                            tmp.push_back(yy);
                        }
                    }
                }
            }
            if(tmp.empty()) { return false; }
            else candidate = tmp;
            ++i;
        }

        if(i != n) return false;
        else return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    WordDictionary* ss = new WordDictionary;
    ss->addWord("at");
    ss->addWord("and");
    ss->addWord("an");
    ss->addWord("add");
    cout << ss->search(".");
    cout << ss->search("a");
    cout << ss->search("aa");
    cout << ss->search("a");
    cout << ss-> search(".a");
    cout << ss->search("a.");

    return 0;
}
