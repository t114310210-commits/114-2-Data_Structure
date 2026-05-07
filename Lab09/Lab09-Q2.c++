// --- 私有的刪除方法 ---
TreeNode* deleteNode(TreeNode* node, int val) {

    // 如果目前節點是空的
    // 代表樹中找不到要刪除的值
    if (node == nullptr) {
        return nullptr;
    }

    // 如果刪除值比目前節點小
    // 繼續往左子樹搜尋
    if (val < node->data) {
        node->left = deleteNode(node->left, val);
    }

    // 如果刪除值比目前節點大
    // 繼續往右子樹搜尋
    else if (val > node->data) {
        node->right = deleteNode(node->right, val);
    }

    // 找到要刪除的節點
    else {

        // 情況一：
        // 節點沒有左子樹
        if (node->left == nullptr) {

            // 暫存右子節點
            TreeNode* temp = node->right;

            // 釋放目前節點記憶體
            delete node;

            // 回傳右子節點
            return temp;
        }

        // 情況二：
        // 節點沒有右子樹
        else if (node->right == nullptr) {

            // 暫存左子節點
            TreeNode* temp = node->left;

            // 刪除目前節點
            delete node;

            // 回傳左子節點
            return temp;
        }

        // 情況三：
        // 節點同時擁有左右子樹
        else {

            // 找出右子樹中的最小值
            TreeNode* temp = findMin(node->right);

            // 用右子樹最小值取代目前節點
            node->data = temp->data;

            // 刪除右子樹中原本的最小值節點
            node->right = deleteNode(node->right, temp->data);
        }
    }

    // 回傳更新後的樹
    return node;
}
