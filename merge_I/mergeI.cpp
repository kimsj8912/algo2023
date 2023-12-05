#include <iostream>
using namespace std;
#define MAX_SIZE 1000
int comNum;

void mergeSortI(int v[], int n);
void merge(int a[], int low, int mid, int high);

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

        mergeSortI(a, n);
        cout << comNum << endl;
    }
    return 0;
}

void mergeSortI(int v[], int n){
    int size = 1;
    while (size < n) {
        for (int i = 0; i < n; i+=2*size) {
            int low = i;
            int mid = low + size - 1;
            int high = min(i+2*size-1, n-1);
            if(mid >= n-1) // merge할 subarray가 1개일 경우
                break;
            merge(v, low, mid, high);
        }
        size *= 2;
    }
}

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