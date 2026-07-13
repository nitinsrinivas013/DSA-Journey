class Solution {
public:
    int addDigits(int num) {

        if(num/10 == 0){
            return num;
        }
        int number = (num % 10) + (num / 10);
        return addDigits(number);
        
    }
};