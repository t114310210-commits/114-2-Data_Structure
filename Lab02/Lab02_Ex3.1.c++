void copyArray(const vector<int>& source, vector<int>& dest) {
    // 1. 初始化 i = 0 (1次)
    // 2. 條件判斷 i < source.size() (n+1次)
    // 3. 索引遞增 i++ (n次)
    for (int i = 0; i < source.size(); i++) {
        
        // 4. 存取 source[i] 並賦值給 dest[i] (每圈約 3 次操作)
        // 注意：這裡假設 dest 的空間已經足夠 (size >= source.size())
        dest[i] = source[i]; 
    }
}
