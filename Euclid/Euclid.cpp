#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int testCases;
    int a, b;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);   
}