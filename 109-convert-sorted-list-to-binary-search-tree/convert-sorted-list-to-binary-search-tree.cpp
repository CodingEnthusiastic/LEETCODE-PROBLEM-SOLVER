/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* dp(int start,int end,vector<int>&nums)
    {
        if(start>end)
        {
            return nullptr;
        }
        int mid=start+((end-start)/2);
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=dp(start,mid-1,nums);
        root->right=dp(mid+1,end,nums);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)
        {
            return nullptr;
        }
        int length=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            length++;
            temp=temp->next;
        }
        vector<int>nums(length,0);
        temp=head;
        int index=0;
        while(temp!=nullptr)
        {
            nums[index++]=temp->val;
            temp=temp->next;
        }
        return dp(0,nums.size()-1,nums);
    }
};