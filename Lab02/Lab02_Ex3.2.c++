int countElement(const vector<int>& arr, int target) {
    // 1. 初始化計數器 (1次)
    int count = 0;

    // 2. 迴圈控制：初始化 i=0 (1次)、判斷條件 (n+1次)、索引遞增 (n次)
    for (int i = 0; i < arr.size(); i++) {
        
        // 3. 條件判斷：存取 arr[i] 並與 target 比較 (每圈執行 1 次)
        if (arr[i] == target) {
            
            // 4. 符合條件時：計數器遞增 (最多執行 n 次)
            count++;
        }
    }

    // 5. 回傳結果 (1次)
    return count;
}
