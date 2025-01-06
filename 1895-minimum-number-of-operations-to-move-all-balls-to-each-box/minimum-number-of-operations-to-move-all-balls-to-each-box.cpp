class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>ones;
        int n=boxes.size();
        vector<int>ans(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                ones.push_back(i);
            }
        };
        for(int i=0;i<n;i++)
        {
            int j=0;
            while(j<ones.size())
            {
                int diff=ones[j]-i;
                sum=sum+abs(diff);
                j++;
            };
            ans[i]=sum;
            sum=0;
        };
        return ans;
    }
};
