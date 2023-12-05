#include <iostream>
#include <vector>
using namespace std;
#define MAX_NUM 1001

vector<int> a[MAX_NUM];
bool visited[MAX_NUM];

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < a[node].size(); i++) {
        int next = a[node][i];
        if (visited[next] == false) {
            dfs(next);
        }
    }
}

int main() {
    int numOftestCases;
    cin >> numOftestCases;
    for (int i = 0; i < numOftestCases; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            boolean[] visited = new boolean[N + 1];
            int cntComponent = 0;
            // 각 정점에 대해서 한번씩 확인.
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) { // 방문했던 정점은 지나치므로, 연결이 떨어진 정점에 대해서만 카운트
                    dfs(i); // dfs 탐색
                    cntComponent++;
                }
            }
        }
    }

    return 0;
}