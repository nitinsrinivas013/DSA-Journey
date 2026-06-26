class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        
        vector <int> prefixSum(n);
        vector <int> suffixSum(n);
        
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        
        
        for(int i=1; i<n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            suffixSum[i] = suffixSum[i+1] + nums[i];
        }
        
        for(int i=0; i<n; i++){
            
            if(prefixSum[i] == suffixSum[i]){
                return i;
            }
            
        }
        return -1;    
    }
};