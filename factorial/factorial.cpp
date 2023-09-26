#include <iostream>
using namespace std;

int factorial(int n);
int answer;

int main() {
    int testCases;
    int n;
    long long int result;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> n;
        result = factorial(n);
        while (result % 10 == 0) {
                result = result * 0.1;
        }
        cout << result % 1000 << endl;
    }

    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    answer = n * factorial(n-1);
    answer %= 100000;
    return answer;
}