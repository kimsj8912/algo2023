#include <iostream>
using namespace std;

int fibo(int n);

int main() {
    int testCases;
    int n;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> n;
        cout << fibo(n) << endl;
    }

    return 0;
}

int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if(n > 1) {
        return (fibo(n-1) + fibo(n-2));
    }
}