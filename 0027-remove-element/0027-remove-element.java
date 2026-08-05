class Solution {
    public int removeElement(int[] nums, int val) {

        int valIndex = 0;
        int n = nums.length;

        for(int i=0; i<n; i++){
            if(nums[i] != val){
                int temp = nums[i];
                nums[i] = nums[valIndex];
                nums[valIndex] = temp;
                valIndex++;
            }
        }
        return valIndex;
    }
}