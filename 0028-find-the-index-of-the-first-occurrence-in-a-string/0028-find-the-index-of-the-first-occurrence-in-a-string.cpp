class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        int startingIndex = -1;
        int i = 0;

        while(i < n){

            int index = 0;

            if(haystack[i] == needle[index]){

                startingIndex = i;

                index++;
                i++;

                while(index < m && i < n && haystack[i] == needle[index]){

                    index++;
                    i++;
                }

                if(index == m){
                    return startingIndex;
                }
                else{
                    i = startingIndex;
                }
            }
            i++;
        }
        return -1;
    }
};