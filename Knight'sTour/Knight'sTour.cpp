#include <iostream>
using namespace std;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knightTour(int m, int n, point pos, int counter);

int main() {
    int numTestCases;
    int m, n, s, t; //체스행, 체스열, 기사행, 기사열
    point start;
    cin >> numTestCases;
    for(int i = 0; i<numTestCases; i++) {
        cin >> m >> n >> s >> t;
        start.y = s;
        start.x = t;
        
        for(int f = 0; f < m; f++) {
            for(int g = 0; g < n; g++) {
                board[f][g] = UNMARK;
            }
        } //보드 초기화

        board[start.y][start.x] = MARK; //시작점 마크
        path[start.y][start.x] = 1; //시작점 path counter 1로 설정

        if(knightTour(m, n, start, 1)) { //마지막셀까지 다 방문하면
            cout << 1 << endl;
            for(int o = 0; o<m; o++) {
                for(int p = 0; p<n; p++) {
                    cout << path[o][p] << " ";
                }
                cout << "\n";
            } //출력
        }
        else
            cout << 0 << endl;
            

    }
    return 0;
}

int knightTour(int m, int n, point pos, int counter) {
    int i;
    point next;

    if(counter == m*n)
        return 1;
    
    for(i = 0; i<8; i++) {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if((next.x >= 0) && (next.x < n) && (next.y >= 0) &&
        (next.y < m) && (board[next.y][next.x] != MARK)) {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter+1;

            if(knightTour(m, n, next, counter+1))
                return 1;
            
            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}
