class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum=0;
        long long sqsum=0;
        int n=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=grid[i][j];
                sqsum+=(long long)pow(grid[i][j],2);
            }
        }
        n=n*n;
        long long n1=n;
        long long exsum=(n1*(n1+1))/2;
        long long exsqsum=(n1*(n1+1)*(2*n1+1)/6);
        int r=(((sqsum-exsqsum)/(sum-exsum))+(sum-exsum))/2;
        int s=(((sqsum-exsqsum)/(sum-exsum))-(sum-exsum))/2;
        return {r,s};
    }
};