class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map <int,int> mpp;

        for(int i=0; i<n; i++){
            int number = nums[i];
            int difference = target - nums[i];

            if(mpp.find(difference) != mpp.end()){
                return {i, mpp[difference]};
            }
            else{
                mpp[nums[i]] = i; 
            }
        }
        return {};
    }
};