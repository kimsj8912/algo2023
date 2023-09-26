#include <iostream>
#include <string>
using namespace std;

char tmp_f;
char tmp_l;

string reverse(string s, int first, int last);

int main() {
    int testCases;
    string s;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> s;
        cout << reverse(s, 0, s.length()-1) << endl;
    }

    return 0;
}

string reverse(string s, int first, int last) {
    if (last <= first) {
        return s;
    }
    tmp_f = s[first];
    tmp_l = s[last];
    s.erase(first, 1);
    s.insert(first, 1, tmp_l);
    s.erase(last, 1);
    s.insert(last, 1, tmp_f);

    return reverse(s, first+1, last-1);
}