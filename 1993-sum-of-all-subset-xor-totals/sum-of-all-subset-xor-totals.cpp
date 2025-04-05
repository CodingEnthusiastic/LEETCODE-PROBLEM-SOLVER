class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        vector<int>n;
        n.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            //either take
            int k=n.size();
            for(int j=0;j<k;j++)
            {
                n.push_back(n[j]^nums[i]);
            }
        }
        for(int i=0;i<n.size();i++)
        {
            sum+=n[i];
        }
        return sum;
    }
};