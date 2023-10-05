#include <iostream>
#include <string>
using namespace std;

string permuteString(string str, int begin, int end);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        string str, result;
        cin >> str;
        result = permuteString(str, 0, str.length());
    }
    return 0;
}

string permuteString(string str, int begin, int end) {
    int i;
    int range = end - begin;
    string tmp_b, tmp_i;

    if(range == 1)
        return str;
    else {
        for(i = 0; i < range; i++) {
            tmp_b = str[begin];
            tmp_i = str[begin+i];

            //swap
            str.replace(begin, 1, tmp_i);
            str.replace(begin+i, 1, tmp_b);
            //reculsive
            permuteString(str, begin+1, end);
            //recover
            str.replace(begin, 1, tmp_b);
            str.replace(begin+i, 1, tmp_i);
        }
    }
        
}