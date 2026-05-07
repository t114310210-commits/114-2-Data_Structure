Lab09-Q1
Complete the following parts in the sample code:  
- deleteNode



Code
#include <iostream>
using namespace std;

// ========================
// 樹的節點類別
// ========================
class TreeNode {
public:
    int data;           // 節點儲存的資料
    TreeNode* left;     // 指向左子節點
    TreeNode* right;    // 指向右子節點

    // 節點建構子：設定資料並初始化左右指標為空
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ========================
// 二元搜尋樹類別
// ========================
class BinarySearchTree {
private:
    TreeNode* root; // 根節點指標

    // --- 私有的遞迴插入方法 ---
    TreeNode* insert(TreeNode* node, int val) {

        // 找到空位置，建立新節點
        if (node == nullptr) {
            return new TreeNode(val);
        }

        // 插入左子樹
        if (val < node->data) {
            node->left = insert(node->left, val);
        }

        // 插入右子樹
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        // 如果值重複則不插入
        return node;
    }

    // --- 私有的遞迴搜尋方法 ---
    bool search(TreeNode* node, int target) {

        // 找不到
        if (node == nullptr)
            return false;

        // 找到
        if (node->data == target)
            return true;

        // 往左找
        else if (target < node->data)
            return search(node->left, target);

        // 往右找
        else
            return search(node->right, target);
    }

    // --- 私有的中序遍歷方法 ---
    void inOrderTraversal(TreeNode* node) {

        if (node == nullptr)
            return;

        // 左
        inOrderTraversal(node->left);

        // 根
        cout << node->data << " ";

        // 右
        inOrderTraversal(node->right);
    }

    // --- 私有的刪除方法 ---
    TreeNode* deleteNode(TreeNode* node, int val) {

        // 找不到節點
        if (node == nullptr) {
            return nullptr;
        }

        // 往左子樹找
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        }

        // 往右子樹找
        else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        }

        // 找到要刪除的節點
        else {

            // 情況1：沒有左子節點
            if (node->left == nullptr) {

                TreeNode* temp = node->right;

                delete node;

                return temp;
            }

            // 情況2：沒有右子節點
            else if (node->right == nullptr) {

                TreeNode* temp = node->left;

                delete node;

                return temp;
            }

            // 情況3：左右子節點都存在
            else {

                // 找右子樹中的最小值
                TreeNode* temp = findMin(node->right);

                // 用最小值取代目前節點
                node->data = temp->data;

                // 刪除右子樹中的最小值
                node->right = deleteNode(node->right, temp->data);
            }
        }

        return node;
    }

    // --- 私有的找最小值方法 ---
    TreeNode* findMin(TreeNode* node) {

        // 一直往左走找到最小值
        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

public:

    // --- 建構子 ---
    BinarySearchTree() : root(nullptr) {}

    // --- 公開插入方法 ---
    void insert(int val) {
        root = insert(root, val);
    }

    // --- 公開搜尋方法 ---
    bool search(int target) {
        return search(root, target);
    }

    // --- 公開中序遍歷方法 ---
    void displayInOrder() {

        cout << "樹的中序遍歷（排序後）結果：" << endl;

        inOrderTraversal(root);

        cout << endl;
    }

    // --- 公開刪除方法 ---
    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
};

int main() {

    BinarySearchTree bst;

    // 預設插入資料
    int values[] = { 7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5 };

    int n = sizeof(values) / sizeof(values[0]);

    // 插入資料
    for (int i = 0; i < n; ++i) {
        bst.insert(values[i]);
    }

    // 使用者輸入搜尋值
    int key;

    cout << "請輸入要搜尋/新增的鍵值：";

    cin >> key;

    // 搜尋是否存在
    if (bst.search(key)) {

        cout << "值 " << key << " 已存在樹中，不新增。" << endl;
    }
    else {

        cout << "值 " << key << " 不存在，已新增進樹中。" << endl;

        bst.insert(key);
    }

    // 顯示目前樹
    bst.displayInOrder();

    // 輸入刪除值
    int deleteKey;

    cout << "請輸入要刪除的鍵值：";

    cin >> deleteKey;

    // 刪除節點
    bst.deleteValue(deleteKey);

    // 顯示刪除後結果
    cout << "刪除後的樹（中序遍歷）：" << endl;

    bst.displayInOrder();

    return 0;
}




