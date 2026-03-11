int findMax(const vector<int>& arr, int& count) {
    // 1. 初始化 (int max = arr[0], int i = 1)
    int max = arr[0];
    count++; // 初始化 max

    // 2. 迴圈操作
    for (int i = 1; i < arr.size(); i++) {
        count++; // 每次迴圈的比較 (i < arr.size())
        
        // 3. 比較與賦值
        count++; // 執行 if 比較 (arr[i] > max)
        if (arr[i] > max) {
            max = arr[i];
            count++; // 執行賦值
        }
        
        count++; // 執行迴圈增量 (i++)
    }
    count++; // 最後一次失敗的迴圈比較 (i < arr.size())

    // 4. 回傳
    count++; // 執行 return
    return max;
}
