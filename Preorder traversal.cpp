#include <iostream>

// Define a structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform a preorder traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Visit the current node
    std::cout << root->data << " ";

    // Recursively traverse the left subtree
    preorderTraversal(root->left);

    // Recursively traverse the right subtree
    preorderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Remember to free the memory allocated for the tree nodes
    delete root;
    delete root->left;
    delete root->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;

    return 0;
}
