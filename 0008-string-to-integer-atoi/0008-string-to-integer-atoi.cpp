class Solution {
public:

    void helper(int index, string s, long long &number, bool &isNegative){

        if(index == s.length() || !isdigit(s[index])){
            return;
        }
        int digit = s[index] - '0';

        if(!isNegative){
            if (number > INT_MAX / 10 ||
                (number == INT_MAX / 10 && digit > 7)
                ) 
                {
                    number = INT_MAX;
                    return;
                }    
        }
        else{
            if (number > (long long)INT_MAX / 10 ||
                (number == (long long)INT_MAX / 10 && digit > 8)
                ) 
                {
                    number = (long long)INT_MAX + 1;
                    return;
                }    
        }

        number = number * 10 + digit;
        helper(index + 1, s, number, isNegative);
    }

    int myAtoi(string s) {



        long long number = 0;
        bool isNegative = false;
        int index = 0;

        while(index < s.length() && isspace(s[index])){
            index++;
        }
        if(index < s.length() && (s[index] == '-' || s[index] == '+')){
            if(s[index] == '-'){
                isNegative = true;
            }
            index++;
        }

        helper(index, s, number, isNegative);

        if(isNegative){
            number = -number;
        }
        
        return (int)number;
    }
};