class Solution {
public:
    int waysToSplitArray(vector<int>& n) {
        vector<long long int>nums(n.size(),0);
        long long int sum=n[0];
        nums[0]=n[0];
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=n[i];
            nums[i]+=nums[i-1];
            sum+=n[i];
        }
        int counter=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            long long int leftsum=nums[i];
            long long int rightsum=nums[nums.size()-1]-leftsum;
            if(leftsum >= rightsum)
            {
                counter++;
            }
        }
        cout<<nums[nums.size()-1]<<' '<<nums.size()-1<<endl;
        cout<<sum<<endl;
        return counter;
    }
};