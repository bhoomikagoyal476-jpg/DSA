class Solution {
public:
void solve(int index, vector<int>& nums, vector<int>& subset,
               vector<vector<int>>& ans) {
                ans.push_back(subset);
                for(int i=index;i<nums.size();i++){
                    subset.push_back(nums[i]);
                    solve(i+1,nums,subset,ans);
                    subset.pop_back();
                }
               } 

    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
          vector<int> subset;
          solve(0,nums,subset,ans);
          return ans;
        
    }
};