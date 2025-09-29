class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int diff = 2; diff < n; ++diff){
            for(int ind = 0; ind < n-diff; ++ind){
                int s = ind, e = ind+diff;
                dp[s][e] = INT_MAX;
                for(int t = s+1; t < e; ++t){
                    dp[s][e] = min(dp[s][e], dp[s][t] + dp[t][e] + values[s]*values[t]*values[e]);
                }
            }
        }
        return dp[0][n-1];
    }
};