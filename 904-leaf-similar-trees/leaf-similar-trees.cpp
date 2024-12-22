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
    void inorder(TreeNode* root,vector<int>&num,int prev)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->left==nullptr&&root->right==nullptr)
        {
            num.push_back(root->val);
            return;
        }
        inorder(root->left,num,root->val);
        inorder(root->right,num,root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>num1;
        vector<int>num2;
        inorder(root1,num1,root1->val);
        inorder(root2,num2,root2->val);
        if(num1.size()!=num2.size())
        {
            return false;
        }
        for(int i=0;i<num1.size();i++)
        {
            if(num1[i]!=num2[i])
            {
                return false;
            }
        }
        return true;
    }
};