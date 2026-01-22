/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode*root,int& ans){
        if(root==NULL){
            return 0;
        }
        int x=solve(root->left,ans);
        int y=solve(root->right,ans);
        ans+=abs(x)+abs(y);
        return root->val-1+x+y;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans=0;
        int x=solve(root,ans);
        return ans;
    }
};