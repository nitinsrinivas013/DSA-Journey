class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map <char, int> mpp;
        
        int n = s.length();
        int maxFreq = 0;
        int changesNeeded = 0;
        int j = 0;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            mpp[s[i]]++;
            maxFreq = max(maxFreq, mpp[s[i]]);

            changesNeeded = (i - j + 1) - maxFreq;

            while(changesNeeded > k){
                mpp[s[j]]--;
                j++;
                changesNeeded = (i - j + 1) - maxFreq;
            }
            maxLen = max(maxLen, i-j+1);

        }
        return maxLen;       
    }
};