#include <iostream>
using namespace std;
#define MAXNUM 1000

void shellSort(int A[], int n);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int n;
        cin >> n;
        int a[MAXNUM];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        shellSort(a, n);
    }
    return 0;
}

void shellSort(int A[], int n) {
    int numOfcomp = 0;
    int numOfswap = 0;
    int shrinkRatio = 2;
    int gap = n / shrinkRatio;

    while(gap > 0) {
        for(int i = gap; i < n; i++) {
            int tmp = A[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                numOfcomp++; //comp
                if(A[j-gap] > tmp) {
                    numOfswap++; //swap
                    A[j] = A[j-gap];
                }
                else    break;
            }
            A[j] = tmp;
        }
        gap /= shrinkRatio;
    }
    cout << numOfcomp << " " << numOfswap << endl;
}