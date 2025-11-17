class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(i==j){
                j++;
                continue;
            }
            if(nums[i]!=1){
                i++;
                continue;
            }
            if(nums[j]!=1){
                j++;
                continue;
            }
            if(j-i<=k){
                return false;
            }
            i=j;
            j++;
        }
        return true;
    }
};