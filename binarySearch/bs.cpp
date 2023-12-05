#include <iostream>
using namespace std;
#define MAXSIZE 100

int bs(int a[], int left, int right, int value);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i<numTestCases; i++) {
        int value, n;
        int a[MAXSIZE];
        cin >> n >> value;

        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }

        cout << bs(a, 0, n-1, value) << endl;
    }
}

int bs(int a[], int left, int right, int value) {
    int mid;

    if(left > right)    return -1;
    else {
        mid = (int)(left+right)/2;
        if(a[mid] == value)  return mid;
        else if(a[mid] > value)
            return bs(a, left, mid-1, value);
        else
            return bs(a, mid+1, right, value);
    }
}