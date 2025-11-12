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
    int solve(TreeNode*root,bool inc,unordered_map<TreeNode*,int>& max_inc,unordered_map<TreeNode*,int>& max_exc){
        if(root==NULL){
            return 0;
        }
        if(inc && max_inc[root]!=0){
            return max_inc[root];
        }
        if(!inc && max_exc[root]!=0){
            return max_exc[root];
        }
        if(inc){
            return max_inc[root]=root->val+solve(root->left,false,max_inc,max_exc)+solve(root->right,false,max_inc,max_exc);
        }
        int x=max(solve(root->left,true,max_inc,max_exc),solve(root->left,false,max_inc,max_exc));
        int y=max(solve(root->right,true,max_inc,max_exc),solve(root->right,false,max_inc,max_exc));
        return max_exc[root]=x+y;
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> max_inc;
        unordered_map<TreeNode*,int> max_exc;
        return max(solve(root,true,max_inc,max_exc),solve(root,false,max_inc,max_exc));
    }
};