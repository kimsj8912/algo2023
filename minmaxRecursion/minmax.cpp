#include <iostream>
using namespace std;

int count_recursive_call;//함수 FindMinMax를 재귀호출하는 횟수를 저장하는 전역변수
void FindMinMax(int a[], int low, int high, int& min, int& max) {
    count_recursive_call++;
    int min1, min2, max1, max2;
    // base case: 원소가 1개인 경우
    if ( low == high ) {
        max = min = a[low];
    }
    // base case: 원소가 2개인 경우
    else if ( low + 1 == high ) {
        if(a[low] > a[high]) {
            max = a[low];
            min = a[high];
        }
        else {
            max = a[high];
            min = a[low];
        }   
    }
    // recursive step: 원소가 2개 이상인 경우
    else {
        int mid = (int) (low + high) / 2;
        FindMinMax(a, low, mid, min1, max1);
        FindMinMax(a, mid+1, high, min2, max2);
        max = (max1 > max2) ? max1 : max2;
        min = (min1 > min2) ? min2 : min1;
    }
}

int main() {
    int num_test_cases;
    int data[100], size;
    cin >> num_test_cases; // 테스트 데이터 개수
    
    while (num_test_cases--) {
        cin >> size; // 주어진 정수의 개수
        count_recursive_call = 0; // 재귀함수 호출횟수를 0으로 초기화
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
        int min = 0;
        int max = 0;
        FindMinMax(data, 0, size - 1, min, max);
        cout << max << " " << min << " " << count_recursive_call << endl;
    }
}