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
    void inorder(TreeNode* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* find(TreeNode* root,int target){
        if(root==NULL){
            return NULL;
        }
        if(root->val==target){
            return root;
        }
        TreeNode* x=find(root->left,target);
        TreeNode* y=find(root->right,target);
        if(x){
            return x;
        }
        return y;
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int i=-1,j=-1;
        for(int k=0;k<arr.size();k++){
            if(i==-1 && arr[k]!=temp[k]){
                i=arr[k];
                j=temp[k];
                break;
            }
        }
        TreeNode* a=find(root,i);
        TreeNode* b=find(root,j);
        int t=b->val;
        b->val=a->val;
        a->val=t;
    }
};