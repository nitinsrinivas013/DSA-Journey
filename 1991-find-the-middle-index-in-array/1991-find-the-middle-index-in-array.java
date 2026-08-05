class Solution {
    public int findMiddleIndex(int[] nums) {

        int size = nums.length;

        int[] prefixSum = new int[size];
        int[] suffixSum = new int[size];

        prefixSum[0] = nums[0];

        for(int i=1; i<size; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        suffixSum[size-1] = nums[size-1];

        for(int i=size-2; i>=0; i--){
            suffixSum[i] = suffixSum[i+1] + nums[i];
        }

        for(int i=0; i<size; i++){
            if(suffixSum[i] == prefixSum[i]){
                return i;
            }
        }
        return -1;   
    }
}