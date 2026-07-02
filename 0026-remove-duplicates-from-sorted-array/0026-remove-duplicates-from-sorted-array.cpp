class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int j = 1;

        for(int i=1; i<n; i++){
            if(nums[i] != nums[j-1]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};