class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //count cnsecutive zeroes 
        vector<int>zero;
        zero.push_back(0);
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero[j]++;
            }
            else
            {
                zero.push_back(0);
                j++;
            }
        }

        //count sum of n numbers
        long long total=0;
        for(int i=0;i<zero.size();i++)
        {
            long long a=(long long)zero[i]*(long long)(zero[i]+1);
            a=a/2;
            total=total+(long long)a;
        }

        return total;
    }
};