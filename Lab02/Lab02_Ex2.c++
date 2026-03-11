
void printPairs(const vector<int>& arr) {
    int count = 0; // 用於追蹤總操作次數

    // 外層迴圈初始化與執行
    for (int i = 0; i < arr.size(); i++) {
        count++; // 記錄外層迴圈執行的次數
        
        // 內層迴圈
        for (int j = i + 1; j < arr.size(); j++) {
            count++; // 記錄內層迴圈進入的次數
            
            // 列印操作
            cout << arr[i] << "," << arr[j] << endl;
        }
    }
    cout << "Total operations: " << count << endl;
}
