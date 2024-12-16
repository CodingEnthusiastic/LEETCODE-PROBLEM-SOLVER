class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int min_index=-1;
        int min=INT_MAX;
        for(int i=0;i<k;i++)
        {
            min_index=-1;
            min=INT_MAX;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<min)
                {
                    min_index=j;
                    min=nums[j];
                }
            };
            nums[min_index]=nums[min_index]*multiplier;
        };
        return nums;
    }
};