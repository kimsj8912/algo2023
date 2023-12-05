#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 1001

using namespace std;


class Graph {
public:
    int V; // 정점의 개수
    vector<vector<int>> adj; // 인접 리스트

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void dfsrecul(int v, vector<bool>& visited, int& componentSize) {
        visited[v] = true;
        componentSize++;

        for (int i : adj[v]) {
            if (!visited[i]) {
                dfsrecul(i, visited, componentSize);
            }
        }
    }

    void connectedComponents() {
        vector<bool> visited(V, false);
        int totalComponents = 0;
        int comp_size[MAX_NUM] = {0}; // 연결 요소 크기
        int cnt = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                int componentSize = 0;

                dfsrecul(i, visited, componentSize);

                // 연결된 부분 그래프의 크기를 저장
                comp_size[cnt] = componentSize;
                cnt++;
                totalComponents++;
            }
        }
        sort(comp_size, comp_size + totalComponents); // 의미있는 숫자만 정렬
        cout << totalComponents << " ";
    
        for (int i = 0; i < MAX_NUM; i++) {
            if (comp_size[i] == 0) {
                break;
            }
            cout << comp_size[i] << " ";
        }
        cout << endl;
        return;
    }

};

int main() {
    int t;
    cin >> t; // 테스트 케이스의 개수

    while (t--) {
        int n;
        cin >> n; // 노드의 개수
        Graph g(n);

        // 그래프 생성
        for (int i = 0; i < n; ++i) {
            int k, m;
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                int v;
                cin >> v;
                g.addEdge(k - 1, v - 1); // 1부터 시작하는 노드 번호를 0부터 시작하는 인덱스로 변환
            }
        }


        // Connected Components 크기 출력
        g.connectedComponents();

    }

    return 0;
}