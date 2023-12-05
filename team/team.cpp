#include <iostream>
using namespace std;
#define MAXNUM 101

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int n;
        int count = 0;
        int a[MAXNUM];
        bool v[MAXNUM];
        cin >> n;
        for (int j = 1; j < n+1; j++) {
            cin >> a[j];
            v[j] = false;
        }

        for(int k = 1; k <= n+1; k++) {
            if (v[k]) continue; //방문했는지 검사
        
            count++;
            int o = k;
            v[k] = true;

            while(a[o] != k) {
                o = a[o];
                if(v[o]) {
                    count--;
                    break;
                }
                v[o] = true;
            }
        }

        cout << count << endl;
    }

    return 0;
}