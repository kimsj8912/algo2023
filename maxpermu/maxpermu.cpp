#include <iostream>
using namespace std;
#define MAXNUM 1000

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int n;
        int a[MAXNUM];
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        int length = 0;
        int tmp = 0;

        for(int k = 0; k < n; k++) {
            if(a[k] >= a[k-1]) {
                tmp++;
                if(tmp > length) {
                    length = tmp;
                }
            }
            else {
                tmp = 1;
            }
        }

        cout << length << endl;
    }

    return 0;
}