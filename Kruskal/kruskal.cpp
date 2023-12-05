#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구조체 edge 정의
typedef struct {
    int i, j, weight; // 시작 노드, 끝 노드, 가중치
} edge;

// Union-Find 연산에서 각 노드의 parent 노드 추적
vector<int> parent;

// 자기 자신을 부모로 하는 독립적인 집합으로 각 노드를 초기화
void initial(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int find(int i) {
    if (parent[i] != i) {   // 현재 노드가 루트가 아닌 경우에
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void merge(int i, int j) {
    parent[find(i)] = find(j);  // i집합과 j집합 합치기
}

void kruskal(int n, vector<edge>& edges) {
    // 가중치에 따라 정렬
    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.weight < b.weight;
    });

    // 초기화
    initial(n);
    int totalWeight = 0;

    // 간선 선택
    for (const edge& e : edges) {
        int i = e.i;
        int j = e.j;
        int p = find(i);
        int q = find(j);

        // 사이클이 형성되지 않으면 해당 간선 선택
        if (p != q) {
            merge(p, q);
            totalWeight += e.weight;
        }
    }

    cout << totalWeight << endl;
}

int main() {
    int t;
    cin >> t;

    for (int testCase = 0; testCase < t; ++testCase) {
        int n; // 노드의 개수
        cin >> n;

        vector<edge> edges;
        for (int i = 0; i < n; ++i) {
            int k, m;
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                edge e;
                cin >> e.j >> e.weight;
                e.i = k - 1; // 노드는 1부터 시작하지 않으므로 인덱스 조정
                e.j--;       // 마찬가지로 노드 번호 조정
                edges.push_back(e);
            }
        }

        kruskal(n, edges);
    }

    return 0;
}
