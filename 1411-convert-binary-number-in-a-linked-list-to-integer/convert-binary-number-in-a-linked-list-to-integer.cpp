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
    int getDecimalValue(ListNode* head) {
        int size=1;
        ListNode* temp=head;
        while(temp->next!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        size--;
        temp=head;
        int ans=0;

        cout<<size<<endl;
        while(size!=-1)
        {
            
            int g=0;
            if(temp->val==1)
                g=pow(2,size);
            cout<<g<<endl;
            ans=ans+g;
            temp=temp->next;
            size--;
        }


        return ans;
    }
};