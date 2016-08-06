//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class minHeap {
private:
    vector<pair<int, int>> arr;
    int alen;

    void adjust(int k) {
        if(k * 2 + 1 >= alen) return;

        int j = k * 2 + 1;
        if(k * 2 + 2 < alen && arr[k * 2 + 1].second > arr[k * 2 + 2].second) j = k * 2 + 2;

        if(arr[k].second > arr[j].second) {
            swap(k ,j);
            adjust(j);
        }
    }

    void swap(int k, int j) {
        int tmp = arr[k].first;
        arr[k].first = arr[j].first;
        arr[j].first = tmp;

        tmp = arr[k].second;
        arr[k].second = arr[j].second;
        arr[j].second  = tmp;
    }

    void adjust_all() {
        for(int k = alen - 1; k >= 0; --k) {
            adjust(k);
        }
    }

public:

    minHeap(int n) {
        alen = n;
    }

    vector<int> getArr() {
        vector<int> result;
        for(int k = alen - 1; k >= 0; --k) {
            result.push_back(arr[k].first);
        }

        return result;
    }

    void add(int num, int freq) {
        if(arr.size() < alen) {
            arr.push_back(pair<int, int>(num, freq));
            if(arr.size() == alen) {
                adjust_all();
            }
        } else {
            if(freq > arr[0].second) {
                arr[0].first = num;
                arr[0].second = freq;
                adjust(0);
            }
        }
    }
};


class Solution {
    map<int, int> count;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); ++i) {
            if(count.find(nums[i]) != count.end()) {
                count[nums[i]] = count[nums[i]] + 1;
            } else count[nums[i]] = 1;
        }

        minHeap heap(k);

        for(auto i = count.cbegin(); i != count.cend(); ++i) {
            heap.add((*i).first, (*i).second);
        }

        return heap.getArr();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
