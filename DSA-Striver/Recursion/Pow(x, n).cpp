class Solution {
    double solve( double x, long long exp){
        if(exp==0) return 1.0;
        if(exp%2==0) return myPow(x*x, exp/2);
        else return x * myPow(x, exp-1);

    }
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp<0){
            return 1.0 / solve(x, -exp);
        }
        return solve(x,exp);
    }
};