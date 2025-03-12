class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        int pos=0,neg=0;
       /* if(nums[0]>0)
            return nums.size();
        if(nums[nums.size()-1]<0)
            return nums.size();*/
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]>0)
            {
                pos=nums.size()-mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        start=0;
        end=nums.size()-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]<0)
            {
                neg=mid+1;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<pos<<" "<<neg;
        int maximum=max(pos,neg);
        return maximum;
    }
    int max(int a,int b)
    {
        if(a>b)
            return a;
        return b;
    }
};