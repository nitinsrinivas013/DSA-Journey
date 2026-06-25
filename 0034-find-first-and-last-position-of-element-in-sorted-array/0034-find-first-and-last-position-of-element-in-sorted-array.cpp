class Solution {
public:


    int firstOccurrence(vector<int>& nums, int target){

        int n = nums.size();
        int low = 0;
        int high = n-1;
        bool flag = false;

        while(high >= low){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                high = mid - 1;
                if(nums[mid] == target){
                    flag = true;
                }
            }
            else{
                low = mid + 1;
            }
        }
        if(flag){
            return low;
        }
        return -1;
    }

    int lastOccurrence(vector<int>& nums, int target){

        int n = nums.size();
        int low = 0;
        int high = n-1;

        bool flag = false;

        while(high >= low){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                low = mid + 1;
                if(nums[mid] == target){
                    flag = true;
                }
            }
            else{
                high = mid-1;
            }
        }
        if(flag){
            return high;
        }
        return -1;
    }





    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums,target);
        int last = lastOccurrence(nums, target);

        return {first,last};

    }



     
};