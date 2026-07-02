class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();
        int i = 0;
        int j = i+1;

        while(j < size){
            if(nums[j] != nums[i]){
                i++;
                swap(nums[j],nums[i]);
            }
            j++;
        }
        return i+1;
    }
};