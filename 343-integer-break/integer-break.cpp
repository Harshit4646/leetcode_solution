class Solution {
private:
    int solve(int n,vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            int x=solve(n-i,dp);
            ans=max(ans,max(x*i,i*(n-i)));
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};