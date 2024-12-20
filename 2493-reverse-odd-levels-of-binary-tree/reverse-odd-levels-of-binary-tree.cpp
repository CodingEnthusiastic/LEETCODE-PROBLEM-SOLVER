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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>>t;
        
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            vector<TreeNode*>l;
            int counter=q.size();
            while(counter--)
            {
                TreeNode* toper=q.front();
                q.pop();
                if(toper->left!=nullptr)
                {
                    q.push(toper->left);
                }
                if(toper->right!=nullptr)
                {
                    q.push(toper->right);
                }
                l.push_back(toper);
            }
            t.push_back(l);
        }
        temp=root;
        for(int i=0;i<t.size();i++)
        {
            if(i%2==1)
            {
                for(int j=0;j<t[i].size()/2;j++)
                {
                    int a=t[i][j]->val;
                    t[i][j]->val=t[i][t[i].size()-j-1]->val;
                    t[i][t[i].size()-j-1]->val=a;
                }
            }
        }

        return root;
    }
};