class Solution {
public:
    int fib(int n) {

        vector<int> dp(n+1, -1);

        return fib(n, dp);

    }

    int fib(int n, vector<int>& dp){

        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return fib(n-1, dp) + fib(n-2, dp);
    }
};