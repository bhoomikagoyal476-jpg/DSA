class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
int ans = nums[0];

for (int i = 1; i < nums.size(); i++) {
    best = max(nums[i], best + nums[i]);
    ans = max(ans, best);
}

return ans;
    }
};