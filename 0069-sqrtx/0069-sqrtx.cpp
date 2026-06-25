class Solution {
public:
    int mySqrt(int x) {

        if(x == 1 || x == 0){
            return x;
        }


        int low = 2;
        int high = x/2;

        while(high >= low){
            long long mid = low + (high - low)/2;

            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid > x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low -1;   
    }
};