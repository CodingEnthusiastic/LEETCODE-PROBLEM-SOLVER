class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num=0ll;
        vector<bool>arr(nums.size(),false);
        for(int i=0;i<nums.size();i++)
        {
            num=(num*2+nums[i])%5;
            if(num%5==0)
            {
                arr[i]=true;
            }
        }

        return arr;
    }
};
