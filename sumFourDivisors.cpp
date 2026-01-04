class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // if(nums.size()==1&&nums[0]==1)
        // {
        //     return 0;
        // }
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int count=2;
            int temp=nums[i]+1;
            for(int i2=2;i2*i2<=nums[i];i2++)
            {
                if(i2*i2==nums[i])
                {
                    count++;
                    temp+=i2;
                    break;
                }
                if(nums[i]%i2==0)
                {
                    count+=2;
                    temp+=(i2+(nums[i]/i2));
                }
            }
            if(count==4)
            {
                sum=sum+temp;
            }

        }

        return sum;
    }
};
