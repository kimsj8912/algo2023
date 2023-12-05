#include <iostream>
#include <string>
using namespace std;

#define MAX_LENGTH 101
int count = 0;

int LCS(string s, string t) {
    if(s.size() == 0 || t.size() == 0) {
        return count;
    }
    if (s.size() > 0 && t.size() > 0) {

    }
}

int main() {
    int numOfTestCases;
    cin >> numOfTestCases;
    for (int i = 0; i < numOfTestCases; i++) {
        string s, t;
        cin >> s >> t;
        int ans = LCS(s, t);
        
        cout << ans << endl;
    }
    return 0;
}