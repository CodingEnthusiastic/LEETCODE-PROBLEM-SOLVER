class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int start=0;
        int end=k-1;
        vector<int>res;
        if(k==1)
        {
            return nums;
        }
        while(end<nums.size())
        {
            int i=0;
            for(i=start+1;i<=end;i++)
            {
                if(nums[i]==nums[i-1]+1)
                {
                    continue;
                }
                else
                {
                    res.push_back(-1);
                    break;
                }
            }
            if(i==end+1)
            {
                res.push_back(nums[end]);
            }
            start++;
            end++;
        }

        return res;
    }
};