class Solution {
private:
    int solve(string s,int idx,vector<int>& dp){
        if(idx==s.length()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int sum=0;
        if(idx+1<s.length()) {
            string dig = s.substr(idx,2);
            int x=stoi(dig);        
            if(x>0 && x<=26) {
                sum+=solve(s,idx+2,dp);
            }
        }
        sum+=solve(s,idx+1,dp);
        return dp[idx]=sum;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(101,-1);
        return solve(s,0,dp);
    }
};