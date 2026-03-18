class Solution {
public:
    int findLucky(vector<int>& arr) {
        // 找陣列最大值
        int max = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        
        int* freq = new int[max + 1](); 
        
        // 統計每個數字出現的次數
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            freq[num]++;
        }
        
        // 找最大的 lucky number
        int maxLucky = -1;
        for (int i = 1; i <= max; i++) {
            // 如果數字 i 出現的次數等於 i 本身
            if (freq[i] == i) {
                if (i > maxLucky) {
                    maxLucky = i;
                }
            }
        }
        
        delete[] freq;
        
        return maxLucky;
    }
};
