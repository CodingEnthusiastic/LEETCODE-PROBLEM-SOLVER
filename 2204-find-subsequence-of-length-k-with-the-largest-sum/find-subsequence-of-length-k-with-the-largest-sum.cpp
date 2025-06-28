class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>arr=nums;
        sort(arr.rbegin(),arr.rend());
        vector<int>brr;
        for(int i=0;i<k;i++)
        brr.push_back(arr[i]);
        int mini=brr[k-1];
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(brr[i]==mini)
            count++;
        }

        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > mini)
            {
                ans.push_back(nums[i]);
            }
            else if(nums[i]==mini && count>0)
            {
                count--;
                ans.push_back(nums[i]);
            }
        }


        return ans;
    }
};