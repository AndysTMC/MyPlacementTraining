//lowest common ancestor in a binary search tree

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}


int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    Node* lca = findLCA(root, 10, 14);
    cout << "LCA: " << lca->data << endl;

    lca = findLCA(root, 14, 8);
    cout << "LCA: " << lca->data << endl;

    lca = findLCA(root, 10, 22);
    cout << "LCA: " << lca->data << endl;

    return 0;
}
