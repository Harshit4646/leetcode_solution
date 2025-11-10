class Solution {
private:
    int solve(vector<int>& stones,int idx,int jump,unordered_map<int,int>& m,vector<vector<int>>& dp){
        if(idx==stones.size()-1){
            return 1;
        }
        if(dp[idx][jump]!=-1){
            return dp[idx][jump];
        }
        int x=0;
        int y=0;
        int z=0;
        if(m.find(stones[idx]+jump)!=m.end()){
            x=solve(stones,m[stones[idx]+jump],jump,m,dp);
        }
        if(jump>1 && m.find(stones[idx]+jump-1)!=m.end()){
            y=solve(stones,m[stones[idx]+jump-1],jump-1,m,dp);
        }
        if(m.find(stones[idx]+jump+1)!=m.end()){
            z=solve(stones,m[stones[idx]+jump+1],jump+1,m,dp);
        }
        return dp[idx][jump]=(x||y||z);
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1){
            return false;
        }
        vector<vector<int>> dp(2000,vector<int>(2000,-1));
        unordered_map<int,int> m;
        for(int i=0;i<stones.size();i++){
            m[stones[i]]=i;
        }
        return solve(stones,1,1,m,dp);
    }
};