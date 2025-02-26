class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long pos=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum>0)
            {
                pos=max(pos,sum);

            }
            else
            {
                sum=0;
            }
            nums[i]=nums[i]*(-1);
        }
        long long neg=0;
        sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum>0)
            {
                neg=max(neg,sum);

            }
            else
            {
                sum=0;
            }
            nums[i]=nums[i]*(-1);
        }

        return max(pos,neg);
    }
};