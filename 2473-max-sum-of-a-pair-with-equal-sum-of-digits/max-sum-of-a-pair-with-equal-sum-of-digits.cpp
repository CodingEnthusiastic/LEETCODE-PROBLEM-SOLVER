class Solution {
public:
    int calsum(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<nums.size();i++)
        {
            int sum=calsum(nums[i]);
            //nahi hain
            if(mp1.find(sum)==mp1.end())
            {
                mp1[sum]=nums[i];
            }
            else
            {
                //dusra khali hain
                if(mp1[sum]<=nums[i])
                {
                    mp2[sum]=mp1[sum];
                    mp1[sum]=nums[i];
                }
                else if(mp2.find(sum)==mp2.end())
                {
                    mp2[sum]=nums[i];
                }
                else if(mp2.find(sum)!=mp2.end())
                {
                    if(mp2[sum]<=nums[i])
                    {
                        mp2[sum]=nums[i];
                    }
                }
            }
        }
        int sol=-1;
        for(auto i=mp1.begin();i!=mp1.end();i++)
        {
            if(mp2.find(i->first)!=mp2.end())
            sol=max(sol,i->second+mp2[i->first]);
        }

        return sol;
    }
};