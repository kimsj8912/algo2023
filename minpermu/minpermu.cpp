#include <iostream>
using namespace std;
#define MAXSIZE 1000

int minpermu(int a[], int n, int *start, int *end);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i<numTestCases; i++) {
        int n;
        cin >> n;

        int start, end;
        int a[MAXSIZE];

        for (int j = 0; j <n; j++) {
            cin >> a[j];
        }

        cout << minpermu(a, n, &start, &end) << endl;
    }
}

int minpermu(int a[], int n, int *start, int *end) {
    int maxl = 1; //최장길이
    int currl = 1; //현재길이
    int i, j;

    *start = *end = -1;
    if(n==1)    return 1;

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i] <= a[j]) {
                currl++;
                *start = i;
                *end = j;
                if(currl > maxl)    maxl = currl;
            }
            else {
                currl = 1;
                break;
            }
        }
    }
    return maxl;
}