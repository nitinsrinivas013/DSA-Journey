class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        int n = nums.length;
        int left = 0;

        int sum = 0;
        int minLen = n+1;

        for(int i=0; i<n; i++){

            sum = sum + nums[i];

            while(sum >= target){
                minLen = Math.min(minLen, i-left+1);
                sum = sum - nums[left];
                left++;
            }
        }
        if(minLen == n+1){
            return 0;
        }
        return minLen;
    }
}