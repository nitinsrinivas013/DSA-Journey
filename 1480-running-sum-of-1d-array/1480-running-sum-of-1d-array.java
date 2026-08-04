class Solution {
    public int[] runningSum(int[] nums) {

        int size = nums.length;
        int[] runningSum = new int[size];

        runningSum[0] = nums[0];

        for(int i=1; i<size; i++){
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        return runningSum;
    }
}