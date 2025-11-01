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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=head,*prev=NULL,*h=NULL;
        sort(nums.begin(),nums.end());
        while(temp!=NULL)
        {
            int target=temp->val;
            int start=0;
            int end=nums.size()-1;
            bool flag=0;
            while(start<=end)
            {
                int mid=start+((end-start)/2);
                if(nums[mid]==target)
                {
                    flag=1;
                    cout<<"YES"<<' ';
                    break;
                }
                else if(nums[mid] > target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            };
            if(flag==0)
            {
                if(prev==NULL)
                {
                    prev=temp;
                    h=temp;
                    temp=temp->next;
                }
                else
                {
                    prev->next=temp;
                    prev=temp;
                    temp=temp->next;
                }
                //cout<<temp->val<<' ';
            }
            else
                temp=temp->next;
        };
        if(h==NULL)
           return NULL;
        prev->next=NULL;
        return h;
    }
};
