class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                if(prefix[nums.size()-1]-prefix[0]==0)
                {
                    return i;
                }
                else
                {
                    continue;
                }
            }
            else if(i==nums.size()-1)
            {
                if(prefix[nums.size()-2]==0)
                {
                    return i;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if(prefix[i-1]==prefix[nums.size()-1]-prefix[i])
                {
                    return i;
                }
                else
                {
                    continue;
                }
            }
        }
        return -1;
    }
};