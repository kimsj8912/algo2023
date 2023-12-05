#include <iostream>
using namespace std;
#define MAX_SIZE 1000
int comNum;

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int tmp[MAX_SIZE];

    for(i = low; i <= high; i++) {
        tmp[i] = a[i];
    }

    i = k = low;
    j = mid+1;
    while(i<=mid && j<=high) {
        comNum++;
        if(tmp[i] <= tmp[j]) { // 비교연산자
            a[k++] = tmp[i++];
        }
        else {
            a[k++] = tmp[j++];
        }
    }
    while(i <= mid) {
        a[k++] = tmp[i++];
    }
    while (j <= high) {
        a[k++] = tmp[j++];
    }
    return;
}

void mergeSort(int v[], int low, int high) {
    int mid;
    if(low == high) {
        return;
    }
    mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v, low, mid, high);
    return;
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int i = 0; i<numTestCases; i++) {
        int n;
        int a[MAX_SIZE];
        comNum = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        mergeSort(a, 0, n-1);
        cout << comNum << endl;
    }
    return 0;
}