//
// Created by fengxuan on 2016/8/25.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord == endWord) return 0;

        wordList.insert(endWord);
        queue<string> toVisited;
        addNextWord(beginWord, wordList, toVisited);
        int result = 2;

        while(!toVisited.empty()) {
            int num = toVisited.size();

            for(int i = 0; i < num; ++i) {
                string str = toVisited.front();
                toVisited.pop();

                if(str == endWord) return result;

                addNextWord(str, wordList, toVisited);
            }

            result++;
        }

        return 0;
    }

    void addNextWord(string word, unordered_set<string>& wordList, queue<string>& toVisited) {
        wordList.erase(word);

        for(int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            for(int j = 0; j < 26; ++j) {
                word[i] = (char)('a' + j);

                if(wordList.find(word) != wordList.end()) {
                    toVisited.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = ch;
        }
    }


    int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord == endWord) return 0;

        unordered_set<string> head, tail, *pHead, *pEnd;
        head.insert(beginWord);
        tail.insert(endWord);

        int result = 2;

        while (!head.empty() && !tail.empty()) {
            if(head.size() < tail.size()) {
                pHead = &head;
                pEnd = &tail;
            } else {
                pHead = &tail;
                pEnd = &head;
            }

            unordered_set<string> candidate;

            for(auto i = pHead->cbegin(); i != pHead->end(); ++i) {
                string word = *i;
                //update every char
                for(int j = 0; j < word.size(); ++j) {
                    char ch = word[j];

                    for(int k = 0; k < 26; ++k) {
                        word[j] = (char)('a' + k);

                        if(pEnd->find(word) != pEnd->end()) return result;

                        if(wordList.find(word) != wordList.end()) {
                            candidate.insert(word);
                            wordList.erase(word);
                        }
                    }
                    word[j] = ch;
                }
            }
            result++;
            swap(*pHead, candidate);
        }
        return 0;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
