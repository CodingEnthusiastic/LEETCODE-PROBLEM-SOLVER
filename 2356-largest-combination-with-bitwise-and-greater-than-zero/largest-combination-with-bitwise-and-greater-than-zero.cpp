class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bitcount(24,0);
        int n=candidates.size();
        for(int i=0;i<24;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((candidates[j]&(1<<i))!=0)
                {
                    bitcount[i]++;
                }
            }
        }
        int maxi=bitcount[0];
        for(int i=0;i<24;i++)
        {
            maxi=max(bitcount[i],maxi);
        }
        return maxi;
    }
};