class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(),false);
        long long x=0;
        for(int i=0;i<nums.size();i++){
            x=(x*2+nums[i])%5;
            ans[i]=(x==0);
        }
        return ans;
    }
};