class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();

        if(size <= 2){
            return size;
        }
        int j = 2;

    

        for(int i=2; i<size; i++){
            if(nums[i] != nums[j-2]){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return j;
    }
};