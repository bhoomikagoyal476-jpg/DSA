class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
         int totalSum = nums[0];
         int best = nums[0];
        int ans = nums[0];
        int worst = nums[0];
        int minAns = nums[0];
        for ( int i =1; i<nums.size(); i++){
            int a = nums[i];
            int b = nums[i]+best;
            best = max(a,b);
            ans= max(ans,best);
            int c = nums [i];
            int d = nums[i]+worst ;
            worst = min(c,d);
            minAns= min(minAns,worst);
             totalSum += nums[i];
        }
         if (ans < 0)
            return ans;

        return max(ans, totalSum - minAns);


        
    }
};