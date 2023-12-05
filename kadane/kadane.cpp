#include <iostream>
using namespace std;

#define MAX 1000

void maxSubsequenceSum(int a[], int n, int *start, int *end);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int p = 0; p < numTestCases; p++) {
        int num;
        int start, end = 0;
        cin >> num;
        int a[MAX];
        for (int l = 0; l < num; l++) {
            cin >> a[l];
        }
        
        maxSubsequenceSum(a, num, &start, &end);
    }
    return 0;
}

void maxSubsequenceSum(int a[], int n, int *start, int *end) {
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for(i=0, j=0; j<n; j++) {
        thisSum += a[j];

        if(thisSum > maxSum) {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum <= 0) {
            i = j+1;
            thisSum = 0;
        }
    }
    
    if(maxSum < 0) {
        maxSum = 0;
        *start = *end = -1;
    }

    cout << maxSum << " " << *start << " " << *end << endl;
    return;
}