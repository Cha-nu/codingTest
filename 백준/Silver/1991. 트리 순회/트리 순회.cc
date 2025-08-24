#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 노드 구조체
struct Node {
    char data;
    Node* left;
    Node* right;
};

// 새로운 노드 생성 함수
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 전위순회 VLR (Visit, Left, Right)
void preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// 중위순회 LVR (Left, Visit, Right)
void inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data;
    inorderTraversal(node->right);
}

// 후위순회 LRV (Left, Right, Visit)
void postorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data;
}

int main() {
    int n;
    cin >> n;

    // 노드를 문자로 빠르게 찾기 위한 맵
    map<char, Node*> nodes;

    // 모든 노드들을 미리 생성
    for (int i = 0; i < n; ++i) {
        char parent, left, right;
        cin >> parent >> left >> right;

        // 부모 노드 가져오기 또는 새로 생성
        if (nodes.find(parent) == nodes.end()) {
            nodes[parent] = createNode(parent);
        }

        // 왼쪽 자식 노드 연결
        if (left != '.') {
            if (nodes.find(left) == nodes.end()) {
                nodes[left] = createNode(left);
            }
            nodes[parent]->left = nodes[left];
        }

        // 오른쪽 자식 노드 연결
        if (right != '.') {
            if (nodes.find(right) == nodes.end()) {
                nodes[right] = createNode(right);
            }
            nodes[parent]->right = nodes[right];
        }
    }
    
    // 루트 노드를 'A'라고 가정
    Node* root = nodes['A'];

    preorderTraversal(root);
    cout << endl;

    inorderTraversal(root);
    cout << endl;

    postorderTraversal(root);
    cout << endl;

    // 메모리 해제
    for (auto const& pair : nodes) {
        delete pair.second;
    }
    
    return 0;
}