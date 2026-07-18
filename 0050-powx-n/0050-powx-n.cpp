class Solution {
public:

    double power(double x, long long exp){

        if(exp == 0){
            return 1.00;
        }
        double half = power(x,exp/2);

        if(exp % 2 == 0){
            return half * half;
        }

        return x * half * half;

    }


    double myPow(double x, int n) {

        long long exponent = n;

        if(exponent < 0){

            x = 1/x;
            exponent = -exponent;

        }
        
        return power(x, exponent);

    }
};