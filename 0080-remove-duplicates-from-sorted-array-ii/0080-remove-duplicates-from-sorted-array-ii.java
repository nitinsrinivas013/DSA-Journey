class Solution {
    public int removeDuplicates(int[] nums) {

        int n = nums.length;
        if(n <= 2){
            return n;
        }

        int extraNum = 2;
        for(int i=2; i<n; i++){

            if(nums[i] != nums[extraNum - 2]){
                int temp = nums[i];
                nums[i] = nums[extraNum];
                nums[extraNum] = temp;

                extraNum++;
            }
            
        }
        return extraNum;
    }
}