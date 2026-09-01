class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int minDifference = INT_MAX;
        int answer = -1;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){

            int left = i + 1;
            int right = n - 1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];
                int difference = abs(sum - target);

                if(minDifference > difference){
                    minDifference = difference;
                    answer = sum;
                }

                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    return target;
                }
            }
        }
        return answer;
    }
};