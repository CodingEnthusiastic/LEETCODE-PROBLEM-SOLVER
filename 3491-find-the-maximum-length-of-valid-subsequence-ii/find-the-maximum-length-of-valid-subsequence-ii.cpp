class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        vector<int> dp;
        for (int i=0; i<k; i++){
            dp.assign(k, 0);
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], int(dp[(i+k-j)%k]+1));
                ans=max(ans, dp[j]);
            }
        }
        return ans;
    }
};