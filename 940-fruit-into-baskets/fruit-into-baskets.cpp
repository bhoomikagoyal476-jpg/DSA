class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
         int low = 0;
        int size = 0;
         for (int high = 0; high < fruits.size(); high++) {
            mp[fruits[high]]++;
            while (mp.size() > 2) {
                mp[fruits[low]]--;
                if (mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }
                low++;
            }
            size = max(size, high - low + 1);
         }
         return size;  
    }
};