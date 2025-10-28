#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int treeHeight(Node* root) {
    if (!root) return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}
void printBinaryTree(Node* root) {
    if (!root) return;

    int h = treeHeight(root);
    int maxWidth = std::pow(2, h) - 1;  // total possible positions
    std::vector<std::vector<std::string>> res(h, std::vector<std::string>(maxWidth, " "));

    // BFS queue holds node and its position index in current level
    std::queue<std::tuple<Node*, int, int>> q; // (node, row, col)
    q.push({root, 0, (maxWidth - 1) / 2});

    while (!q.empty()) {
        auto [node, row, col] = q.front();
        q.pop();
        res[row][col] = std::to_string(node->data);
        if (node->left)
            q.push({node->left, row + 1, col - std::pow(2, h - row - 2)});
        if (node->right)
            q.push({node->right, row + 1, col + std::pow(2, h - row - 2)});
    }

    // Print the matrix row by row
    for (auto& row : res) {
        for (auto& s : row) std::cout << s;
        std::cout << "\n";
    }
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printBinaryTree(root);
    return 0;
}

