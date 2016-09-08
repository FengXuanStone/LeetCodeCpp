//
// Created by fengxuan on 2016/9/7.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

void sort(int *A, int *B, int array_size, int k) {
    int c[k + 1];
    //init
    for(int i = 0; i <= k; ++i) {
        c[i] = 0;
    }
    //update every number
    for(int i = 0; i < array_size; ++i) {
        c[A[i]]++;
    }
    //min numbers
    for(int i = 1; i <= k; ++i) {
        c[i] = c[i] + c[i - 1];
    }
    //sort
    for(int i = array_size - 1; i >= 0; --i) {
        int value = A[i];
        int index = c[value];
        B[index - 1] = value;
        c[value]--;
    }

}

int main() {
    int A[8] = {2, 5, 3, 0, 2, 3, 0, 3}, B[8], i;
    sort(A, B, 8, 5);
    for (i=0; i<= 7; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}
