class Solution {
public:

    long long mod = 1000000007;

    long long power(long long base, long long exponent){

        if(exponent == 0){
            return 1;
        }
        long long val = power(base, exponent/2);
        val = (val * val) % mod;

        if(exponent % 2 == 0){
            return val;
        }
        return (base * val) % mod;

    }

    int countGoodNumbers(long long n) {

        long long evenIndices = (n+1)/2;
        long long oddIndices = (n/2);

        long long evenNums = power(5 , evenIndices);
        long long oddNums = power(4 , oddIndices);

        return (int)((evenNums * oddNums) % mod);
    
    }
};