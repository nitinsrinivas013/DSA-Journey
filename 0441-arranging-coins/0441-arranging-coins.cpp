class Solution {
public:
    int arrangeCoins(int n) {

        int low = 0;
        int high = n;

        while(high >= low){
            long long mid = low + (high - low)/2;
            long long sum = (mid*(mid+1))/2;

            if(n == sum){
                return (int)mid;
            } 
            else if(n < sum){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low - 1;
    }
};