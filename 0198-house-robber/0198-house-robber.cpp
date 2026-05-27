class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector <int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i=2; i<n; i++){
            int rob = nums[i] + dp[i-2];
            int notRob = dp[i-1];

            dp[i] = max(rob, notRob);
        }
        return dp[n-1];
        
    }
};