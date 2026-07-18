class Solution {
public:

    long long mod = 1000000007;

    int power(long long base, long long exp){

        if(exp == 0){
            return 1;
        }
        long long half = power(base, exp/2);
        half = (half * half) % mod;

        if(exp % 2 == 0){
            return half;
        }
        return (base * half) % mod;

    }

    int countGoodNumbers(long long n) {

        long long evenIndices = (n+1)/2;
        long long oddIndices = (n/2);

        long long evenPower = power(5,evenIndices);
        long long oddPower = power(4, oddIndices);

        long long result = (evenPower * oddPower) % mod;

        return (int) result;
        
    }
};