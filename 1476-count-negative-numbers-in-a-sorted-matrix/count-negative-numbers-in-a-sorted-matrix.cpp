class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int low=0;
            int high=grid[i].size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(grid[i][mid]<0){
                    if(mid==0){
                        ans+=grid[i].size();
                        break;
                    }
                    if(grid[i][mid-1]<0){
                        high=mid-1;
                    }
                    else{
                        ans+=(grid[i].size()-mid);
                        break;
                    }
                }
                else{
                    if(mid==(grid[i].size()-1)){
                        break;
                    }
                    if(grid[i][mid+1]>=0){
                        low=mid+1;
                    }
                    else{
                        ans+=(grid[i].size()-mid-1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};