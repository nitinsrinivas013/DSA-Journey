class Solution {
public:

    bool isVowel(char c){
        
        return  tolower(c) == 'a' ||
                tolower(c) == 'e' || 
                tolower(c) == 'i' || 
                tolower(c) == 'o' || 
                tolower(c) == 'u'; 

    }

    string reverseVowels(string s) {

        int n = s.length();

        string vowels = "";

        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                vowels += s[i];
            }
        }
        
        int index = 0;
        for(int i=n-1; i>=0; i--){

            if(isVowel(s[i])){
                s[i] = vowels[index];
                index++;
            }
        }
        return s;
    }
};