#include <iostream>
using namespace std;

struct node
{
 int data;
 struct node* left;
 struct node* right;
};

void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int i = 0; i < numTestCases; i++) {
        int num;
        struct node* root = NULL;

        cin >> num;
        for(int j = 0; j < num; j++) {
            int data;
            cin >> data;
            insert(&root, data);
        }

        cout << size(root);
        cout << height(root);
        cout << sumOfWeight(root);
        cout << maxPathWeight(root);
        mirror(&root);
        preOrder(root); cout >> "\n";        
        inOrder(root); cout >> "\n";
        postOrder(root); cout >> "\n";
        destruct(&root); //BTS의 모든 노드의 동적 메모리 해제
        if (root == NULL)
            cout << "0\n";
        else
            cout << "1\n";

    }
    
    return 0;
}

//데이터 삽입
void insert(struct node** root, int data) {
    return;
}
//전위 탐색
void preOrder(struct node* root) {
    return;
}
//중위 탐색
void inOrder(struct node* root) {
    return;
}
//후위 탐색
void postOrder(struct node* root) {
    return;
}
//노드의 개수
int size(struct node* root) {
    return 0;
}
//높이
int height(struct node* root) {
    return 0;
}
//미러 이미지로 변환하기
int sumOfWeight(struct node* root) {
    return 0;
}
//노드에 저장된 데이터의 값의 합 구하기
int maxPathWeight(struct node* root) {
    return 0;
}
//루트노드부터 단말노드까지의 경로 상의 데이터의 최대합
void mirror(struct node** root) {
    return;
}
//트리노드의 동적 메모리 해제하기
void destruct(struct node** root) {
    return;
}