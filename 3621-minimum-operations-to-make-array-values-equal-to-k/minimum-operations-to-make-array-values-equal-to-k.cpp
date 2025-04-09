class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=INT_MIN;
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>k)
            s.insert(nums[i]);
            if(nums[i]<k)
            {
                return -1;
            }
        }
        return s.size();
    }
};