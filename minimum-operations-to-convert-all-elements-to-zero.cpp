class Solution {
public:
    int minOperations(vector<int>& nums) {
        int top=-1;
        vector<int>st(1e5,0);
        int op=0;
        for (int x : nums){
            while(top!=-1 && x<st[top]) top--;
            if (top==-1 || x>st[top]){
                if (x>0) op++;
                st[++top]=x;
            }
        }
        return op;
    }
};
