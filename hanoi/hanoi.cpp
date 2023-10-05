#include <iostream>
#include <math.h>
using namespace std;

int hanoi(int n, int a, int b, int c, unsigned long long int k);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int i = 0; i < numTestCases; i++) {
        int n;
        unsigned long long int k;
        cin >> n >> k;
        int result = hanoi(n, 1, 2, 3, k);

        cout << result % 10 << " " << (result - (result % 10)) * 0.1 << endl;
    }
    return 0;
}

int hanoi(int n, int a, int b, int c, unsigned long long int k) {
    unsigned long long int total = pow(2, n-1);

    if(n == 1) {
        return (c * 10 + a);
    }
    
    if(k < total) {
            hanoi(n-1, a, c, b, k);
        }
        else if (k == total) {
            return (c * 10 + a);
        }
        else if (k > total) {
            hanoi(n-1, b, a, c, k-total);
        }
}