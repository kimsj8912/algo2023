#include <iostream>
using namespace std;
#define MAXNUM 1000

int swap_h, swap_L, com_h, com_L; // swap과 비교 연산자 횟수

void quicksort_h(int A[], int low, int high);
int partition_h(int A[], int low, int high);

void quicksort_L(int A[], int low, int high);
int partition_L(int A[], int low, int high);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int i = 0; i < numTestCases; i++) {
        swap_h = swap_L = com_h = com_L = 0; // 전역 변수 초기화
        int n; // 주어진 자연수의 개수
        int a[MAXNUM]; // 정렬 데이터
        cin >> n;
        for (int j = 0; j < n; j++) { // 정렬 데이터 입력받기
            cin >> a[j];
        }
        quicksort_h(a, 1, n-2);
        quicksort_L(a, 0, n-1);

        cout << swap_h << " " << swap_L << " " << com_h << " " << com_L << endl;
    }
    return 0;
}

void quicksort_h(int A[], int low, int high) {
    if(low >= high) {
        return;
    }
    int p = partition_h(A, low, high);
    quicksort_h(A, low, p);
    quicksort_h(A, p+1, high);
}

int partition_h(int A[], int low, int high) {
    int pivot = A[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        com_h++;
        while(A[i] < pivot) {
            i++;
            com_h++;
            if (A[i] >= pivot)  com_h--;
        }
        com_h++;
        while(A[j] > pivot) {
            j--;
            com_h++;
            if (A[i] <= pivot)  com_h--;
        }

        if(i < j) {
            // swap
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            swap_h++;
        }
        else {
            return j;
        }
    }
}

void quicksort_L(int A[], int low, int high) {
    if(low >= high) {
        return;
    }
    int p = partition_L(A, low, high);
    quicksort_L(A, low, p-1);
    quicksort_L(A, p+1, high);
}


int partition_L(int A[], int low, int high) {
    int pivot = A[low];
    int j = low;
    for (int i = low+1; i < high; i++) {
        com_L++;
        if(A[i] < pivot) { // 비교
            j++;
            // swap
            swap_L++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int pivot_pos = j;
    // swap
    swap_L++;
    int tmp = A[pivot_pos];
    A[pivot_pos] = A[low];
    A[low] = tmp;
    return pivot_pos;
}