class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long int count=0;
        unordered_map<int,vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]-i].push_back(i);
        }
        long long int similar=0;
        for(auto temp=ans.begin();temp!=ans.end();temp++)
        {
            long long int t=temp->second.size();
            t=t*(t-1);
            t=t/2;
            similar=similar+t;
        };
        long long int totalPairs=(nums.size())*(nums.size()-1);
        totalPairs=totalPairs/2;
        count=totalPairs-similar;
        return count;
    }
};