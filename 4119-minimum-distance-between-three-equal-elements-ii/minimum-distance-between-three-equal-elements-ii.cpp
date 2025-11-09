class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> hash;
        for(int i=0;i<n;i++){
            hash[nums[i]].push_back(i);
        }
        bool found=false;
        int ans=INT_MAX;
        for(auto j:hash) {
            int si=j.second.size();
            if(si>=3){
                found=true;
            }
            auto a=j.second;
            for(int i=0;i<si-2;i++) {
                ans=min(ans,(a[i+1]-a[i])+(a[i+2]-a[i+1])+(a[i+2]-a[i]));
            }
        }
        return found?ans:-1;
    }
};