class Solution {
    public int pivotIndex(int[] nums) {

        int size = nums.length;
        int[] prefixSum = new int[size];
        int[] suffixSum = new int[size];

        prefixSum[0] = nums[0];
        suffixSum[size-1] = nums[size-1];

        for(int i=1; i<size; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        for(int i=size-2; i>=0; i--){
            suffixSum[i] = nums[i] + suffixSum[i+1];
        }
        int index = size-1;
        for(int i=0; i<size; i++){
            if(prefixSum[i] == suffixSum[i]){
                return i;
            }
        }
        return -1;        
    }
}