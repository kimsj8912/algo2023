#include <iostream>
using namespace std;
#define MAXNUM 1000

int result[6];

void bubble(int A[], int n);
void bubble1(int A[], int n);
void bubble2(int A[], int n);

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
        bubble(a, n);
        bubble1(a, n);
        bubble2(a, n);

        cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << endl;
    }
    return 0;
}

void bubble(int A[], int n) {
    int numOfcomp = 0;
    int numOfswap = 0;

    for(int pass = 1; pass < n; pass++) {
        for (int i = 1; i <= n-pass; i++) {
            numOfcomp++;
            if(A[i-1] > A[i]){
                numOfswap++;
                swap(A[i-1], A[i]);
            }
        }
    }

    result[0] = numOfcomp;
    result[1] = numOfswap;
}

void bubble1(int A[], int n)
{
    int numOfcomp = 0;
    int numOfswap = 0;
    bool swapped;

    for(int pass = 1; pass < n; pass++) {
        swapped = false;
        for (int i = 1; i <= n-pass; i++) {
            numOfcomp++;
            if(A[i-1] > A[i]){
                numOfswap++;
                swap(A[i-1], A[i]);
                swapped = true;
            }
        }
        if (swapped == false)   break;
    }

    result[2] = numOfcomp;
    result[3] = numOfswap;
    return;
}
void bubble2(int A[], int n) {
    int numOfcomp = 0;
    int numOfswap = 0;
    int lastSwappedPos = n;
    int swappedPos;

    while(lastSwappedPos > 0) {
        swappedPos = 0;
        for (int i = 1; i < lastSwappedPos; i++) {
            numOfcomp++;
            if(A[i-1] > A[i]){
                numOfswap++;
                swap(A[i-1], A[i]);
                swappedPos = i;
            }
        }
        lastSwappedPos = swappedPos;
    }

    result[4] = numOfcomp;
    result[5] = numOfswap;
    return;
}