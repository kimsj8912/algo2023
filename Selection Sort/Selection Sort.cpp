#include <iostream>

using namespace std;
void selectionSort(int a[], int n) {
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwap = 0; // swap 함수 실행 횟수

    for (int i = 0; i < n - 1; i++) {
        int jMin = i;

        for (int j = i + 1; j < n; j++) {
            countCmpOps++;
            if (a[j] < a[jMin]) {
                jMin = j;
            }
        }
        if (jMin != i) {
            int t = a[jMin];
            a[jMin] = a[i];
            a[i] = t;
            countSwap++;
        }
    }

    cout << countCmpOps << " " << countSwap << endl;

}

int main() {
    int numTestCases;
    int num;
    const int MAX = 1000;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        cin >> num;
        int a[MAX];
        for (int j = 0; j < num; j++) {
            cin >> a[j];
        }

        selectionSort(a, num);
    }

    return 0;
}