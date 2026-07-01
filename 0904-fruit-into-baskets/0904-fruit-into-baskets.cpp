class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        int j = 0;
        unordered_map <int,int> mpp;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            mpp[fruits[i]]++;

            if(mpp.size() > 2){
                mpp[fruits[j]]--;
                if(mpp[fruits[j]] == 0){
                    mpp.erase(fruits[j]);
                }
                j++;
            }
            maxLen = max(maxLen, i-j+1);
        }
        return maxLen;
    }
};