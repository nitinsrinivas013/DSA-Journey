class Solution {
public:

    int tabulationCode(int n){

        int first = 0;
        int second = 1;
        int third = 1;

        int answer = 0;

        for(int i=3; i<=n; i++){
            answer = first + second + third;
            first = second;
            second = third;
            third = answer;

        }
        return answer;
    }

    int tribonacci(int n) {

        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        
        return tabulationCode(n);
    }
};