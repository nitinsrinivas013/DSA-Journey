class Solution {
public:
    int characterReplacement(string s, int k) {

        vector <int> freq(26,0);
        
        int n = s.length();
        int maxFreq = 0;
        int changesNeeded = 0;
        int j = 0;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            changesNeeded = (i - j + 1) - maxFreq;

            while(changesNeeded > k){
                freq[s[j] - 'A']--;
                j++;
                changesNeeded = (i - j + 1) - maxFreq;
            }
            maxLen = max(maxLen, i-j+1);

        }
        return maxLen;       
    }
};