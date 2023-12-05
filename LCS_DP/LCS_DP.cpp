#include <iostream>
#include <string>
using namespace std;

#define MAX_LENGTH 101

int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];

int LCS(string s, string t) {
    int i, j;

    //base cases
    for (i = 0; i <= s.size(); i++) {
        L[i][0] = 0;
    }
    for (i = 1; i <= t.size(); i++) {
        L[0][i] = 0;
    }
    for (i = 1; i <= s.size(); i++) {
        for (j = 1; j <= t.size(); j++) {
            if (s[i-1] == t[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if (L[i][j] == L[i][j-1]) {
                    S[i][j] = 1;
                }
                else {
                    S[i][j] = 1;
                }
            }
        }
    }
    return L[s.size()][t.size()];
}

int main() {
    int numOfTestCases;
    cin >> numOfTestCases;
    for (int i = 0; i < numOfTestCases; i++) {
        string s, t;
        cin >> s >> t;
        int ans = LCS(s, t);
        
        string ansS = "";
        int k = s.size();
        int j = t.size();
        while (i > 0 && j > 0) {
            if (s[k-1] == t[j-1]) {
                string temp = s.substr(k-1, 1);
                const char* a = temp.c_str();
                ansS.append(a);
                k -= 1;
                j -= 1;
            }
            else if (L[k-1][j] > L[k][j-1]) {
                k -= 1;
            }
            else {
                j -= 1;
            }
        }

        cout << ans << " " << ansS << endl;
    }
    return 0;
}

/*
string ansS = "";
        int count, last;
        count = last = 0;
        for (int j = 0; j < s.size(); j++) {
            if (count == ans)   break;

            string temp = s.substr(j, 1);
            const char* f = temp.c_str();
            int index = t.find(f);

            if (index != -1 && ansS.find(f) == -1 && last <= index) {
                ansS.append(f);
                count++;
            }
        }
*/