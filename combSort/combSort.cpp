#include <iostream>
using namespace std;
#define MAXNUM 1000

void combSort(int A[], int n);

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
        combSort(a, n);
    }
    return 0;
}

void combSort(int A[], int n) {
    int numOfcomp = 0;
    int numOfswap = 0;

    int gap = n;
    float shrink = 1.3;
    bool sorted = false;

    while (sorted == false) {
        gap = gap / shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
    }

    int i = 0;
    while(i+gap < n) {
        numOfcomp++; //comp
        if(A[i] > A[i+gap]) {
            swap(A[i], A[i+gap]);
            numOfswap++; //swap
            sorted = false;
        }
        i++;
    }

    cout << numOfcomp << " " << numOfswap << endl;
}