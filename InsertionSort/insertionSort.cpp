#include <iostream>
using namespace std;
#define MAXNUM 1000

void insertionSort(int A[], int n);

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
        insertionSort(a, n);
    }
    return 0;
}

void insertionSort(int A[], int n) {
    int numOfcomp = 0;
    int numOfswap = 0;

    for (int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            numOfcomp++; // comp
            if (A[j-1] > A[j]){
                numOfswap++;
                swap(A[j-1], A[j]);
            }
            else break;
        }
    }
    cout << numOfcomp << " " << numOfswap << endl;
}