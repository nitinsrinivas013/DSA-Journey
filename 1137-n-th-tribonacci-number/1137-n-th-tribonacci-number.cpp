class Solution {
public:

    int memoizationCode(int n, vector<int> &dp){

        if(n == 0){
            dp[n] = 0;
            return 0;
        }
        if(n == 1 || n == 2){
            dp[n] = 1;
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = memoizationCode(n-3, dp) + memoizationCode(n-2, dp) + memoizationCode(n-1, dp);
        return dp[n];
    }

    int tribonacci(int n) {
        
        vector<int> dp(n+1,-1);
        return memoizationCode(n, dp);
    }
};