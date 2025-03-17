class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>mp(501,0);
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        bool flag=0;
        for(auto i=0;i<mp.size();i++)
        {
            if(mp[i]%2==1)
            {
                flag=1;
            }
        }
        return !flag;
    }
};