#include <iostream>
#include <array>
using namespace std;
#define MAXSIZE 1000

void quickSort(int v[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i<numTestCases; i++) {
        int n;
        int v[MAXSIZE];

        cin >> n;
        for(int j = 0; j<n; j++) {
            cin >> v[j];
        }

        quickSort(v, 0, n);

        cout << v[0] << endl;
    }

    return 0;
}

int partition(int a[], int low, int high) {
    int i, j;
    int pivot, pivotPos, tmp;

    pivot = a[low];
    j = low;

    for(i=low+1; i<=high; i++) {
        if(a[i] <= pivot) {
            j++;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        }
    }
    pivotPos = j;
    tmp = a[low]; a[low] = a[pivotPos]; a[pivotPos] = tmp;

    return pivotPos;
}

void quickSort(int v[], int low, int high) {
    int pivotPos;

    if(high > low) {
        pivotPos = partition(v, low, high);
        quickSort(v, low, pivotPos-1);
        quickSort(v, pivotPos+1, high);
    }
    return;
}