class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        bool flag=0;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second%2==1)
            {
                flag=1;
            }
        }
        return !flag;
    }
};