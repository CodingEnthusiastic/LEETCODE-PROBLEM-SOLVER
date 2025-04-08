class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int last=-1;
        map<int,int>mp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
                last=i;
                break;
            }
        }
        int element=last+1;
        int r=ceil((element*1.0)/3.0);
        return r;
    }
};