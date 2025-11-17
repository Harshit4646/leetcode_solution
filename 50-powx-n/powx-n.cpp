class Solution {
private:
    double solve(double x,long long n){
        if(n==0){
            return 1;
        }
        if(n&1){
            return x*solve(x,n-1);
        }
        return solve(x*x,n/2);
    }
public:
    double myPow(double x, int n) {
        bool isnegative=false;
        long long a=n;
        if(n<0){
            isnegative=true;
            a=(-1)*a;
        }
        double ans=solve(x,a);
        if(isnegative){
            return 1/ans;
        }
        return ans;
    }
};