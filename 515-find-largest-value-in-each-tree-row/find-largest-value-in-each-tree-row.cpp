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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(root==nullptr)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()!=0)
        {
            int temp=q.size();
            int mini=INT_MIN;
            while(temp--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
                mini=max(mini,curr->val);
            }
            res.push_back(mini);
        }
        return res;
    }
};