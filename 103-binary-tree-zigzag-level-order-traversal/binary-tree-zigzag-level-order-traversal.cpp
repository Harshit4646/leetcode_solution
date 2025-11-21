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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        int currLevel = 0;

        while (!q.empty()) {
            int len = q.size();
            res.push_back({});

            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front();
                q.pop();

                res[currLevel].push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            currLevel++;
        }
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans=levelOrder(root);
        for(int i=0;i<ans.size();i++){
            if(i&1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};