class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>ones;
        ones.push_back(0);
        int count=0;
        bool iszero=false;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                iszero=true;
                
                if(count>0)
                {
                    ones.push_back(count);
                    count=0;
                    
                }
                if(zero>0)
                {
                    ones.push_back(0);
                }
                zero++;
            }
            else
            {
                count++;
                zero=0;
            }
        }

        if(count>0)
        {
            ones.push_back(count);
        }
        
        int n=nums.size();
        int maxi=ones[0];
        if(iszero==false)
        return n-1;
        else
        {
            maxi=0;
            for(int i=0;i<ones.size()-1;i++)
            {
                maxi=max(maxi,ones[i]+ones[i+1]);
            }
        }

        return maxi;
    }
};