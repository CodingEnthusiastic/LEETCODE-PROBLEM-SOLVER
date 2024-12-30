#define mod 1000000007
class Solution {
public:
    int good(vector<int>&dp,int n, int x0, int x1){
        if( dp[n]!=-1 ) 
        {
            return dp[n];
        }
        long long ans;
        if (n <= x0)
        {
            ans=1;
        }
        if ( n >= x0)
        {
            ans+=good(dp,n-x0, x0, x1);
        }
        if ( n >= x1)
        {
            ans+=good(dp,n-x1, x0, x1);
        }
        return dp[n]=ans%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        if(zero > one)
        {
            int temp=zero;
            zero=one;
            one=temp;
        }
        vector<int>dp(high+1,-1);
        return ((good(dp,high,zero,one)-good(dp,low-1,zero,one)+mod))%mod;
    }
};