#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* buildTree(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        queue<TreeNode*> q;
        root = new TreeNode(arr[0]);
        q.push(root);

        size_t i = 1;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (i < arr.size()) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
                i++;
            }

            if (i < arr.size()) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
                i++;
            }
        }

        return root;
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

    int findMax(TreeNode* node) {
        if (node == nullptr) return INT_MIN;

        int leftMax = findMax(node->left);
        int rightMax = findMax(node->right);

        return max(node->value, max(leftMax, rightMax));
    }
};

int main() {
    BinaryTree tree;

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    tree.buildTree(arr);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    int leftMax = tree.findMax(tree.root->left);
    int rightMax = tree.findMax(tree.root->right);

    cout << "Max left subtree value: " << leftMax << endl;
    cout << "Max right subtree value: " << rightMax << endl;

    return 0;
}
