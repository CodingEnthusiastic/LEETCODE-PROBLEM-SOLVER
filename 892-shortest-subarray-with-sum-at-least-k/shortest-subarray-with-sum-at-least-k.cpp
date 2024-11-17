class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        deque<int>dq;
        vector<long long>prefix(nums.size()+1,0);
        int n=nums.size();
        for(int i=0;i<n;i++) 
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        int result=INT_MAX;
        for(int i=0;i<prefix.size(); i++) 
        {
            while(dq.empty()==0&&prefix[i]-prefix[dq.front()]>=k) 
            {
                result=min(result,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty()&&prefix[i]-prefix[dq.back()]<=0) 
            {
                dq.pop_back();
            }

            dq.push_back(i); 
        }

        if(result==INT_MAX)
        return -1;
        else
        return result;
    }
};
