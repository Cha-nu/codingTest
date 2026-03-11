#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeLinkedList
{
private:
    Node* root;
public:
    BinaryTreeLinkedList() : root(nullptr) {}
    ~BinaryTreeLinkedList(){ RemoveNode(root); }

    Node* GetRoot() { return root; }

    Node* Insert(Node* node, int data)
    {
        if(node == nullptr) return new Node(data);
        if(data < node->data) node->left = Insert(node->left, data);
        else node->right = Insert(node->right, data);
        return node;
    }
    void Insert(int data) {root = Insert(root, data);}

    void PostorderPrint(Node* node)
    {
        if(node == nullptr) return;

        PostorderPrint(node->left);
        PostorderPrint(node->right);
        cout << node-> data << '\n';
    }

    void RemoveNode(Node* node)
    {
        if(node == nullptr) return;

        RemoveNode(node->left);
        RemoveNode(node->right);
        delete node;
    }
};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BinaryTreeLinkedList BinaryTree;
    int n;

    while(cin >> n)
    {
        BinaryTree.Insert(n);
    }

    BinaryTree.PostorderPrint(BinaryTree.GetRoot());
    return 0;
}