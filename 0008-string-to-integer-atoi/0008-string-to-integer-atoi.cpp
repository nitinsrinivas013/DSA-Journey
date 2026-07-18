class Solution {
public:

    void helper(string s, int index, long long &number, bool &isNegative){

        if(index > s.length() || !isdigit(s[index])){
            return;
        }
        int digit = s[index] - '0';

        if(!isNegative){
            if(number > INT_MAX/10 || (number == INT_MAX/10 && digit > 7)){
                number = INT_MAX;
                return;
            }
        }
        else{
            if(number > INT_MAX/10 || (number == INT_MAX/10 && digit > 8)){
                number = (long long) INT_MAX + 1;
                return;
            }
        }

        number = number * 10 + digit;
        helper(s, index+1, number, isNegative);
    }


    int myAtoi(string s) {

        int index = 0;
        long long number = 0;
        int n = s.length();
        bool isNegative = false;

        while(index < n && isspace(s[index])){
            index++;
        }
        if(index < n && (s[index] == '+' || s[index] == '-')){

            if(s[index] == '-'){
                isNegative = true;
            }
            index++;
        }

        helper(s,index,number,isNegative);

        if(isNegative){
            number = -(number);
            return (int)number;
        }

        return number;
        
    }
};