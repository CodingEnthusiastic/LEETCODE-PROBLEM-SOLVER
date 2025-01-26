class Solution {
public:
    int func(int m,int n,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(m<0||n<0)
        {
            return 0;
        }
        if(a[m][n]==1)
        {
            return 0;
        }
        if(m==0&&n==0)
        {
            return 1;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int d=func(m-1,n,a,dp);
        int e=func(m,n-1,a,dp);
        return dp[m][n]=d+e;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,a,dp);
    }
};