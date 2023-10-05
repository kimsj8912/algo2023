#include <iostream>
#include <cmath>
using namespace std;

int expo(int a, int n);

int main() {
    int testCases;
    int a, n;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> a >> n;
        cout << expo(a, n) % 1000 << endl;
    }

    return 0;
}

int expo(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 != 0) {
        return (int)(a * pow(expo(a, (n-1)/2), 2)) % 1000000; 
    }
    else if (n % 2 == 0) {
        return (int)pow(expo(a, n/2), 2) % 1000000;
    }
}