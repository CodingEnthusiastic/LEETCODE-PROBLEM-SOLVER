class Solution {
public:
    long long solve(vector<pair<int,long long>>& vec, int i, vector<long long>& dp) {
        int n = vec.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        long long not_take = solve(vec, i + 1, dp);
        long long take = vec[i].second;
        int j = i + 1;
        while (j < n && vec[j].first - vec[i].first <= 2) j++;
        take += solve(vec, j, dp);

        return dp[i] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> mp;
        for (auto x : power) mp[x] += x;
        vector<pair<int,long long>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end());
        vector<long long> dp(vec.size(), -1);
        return solve(vec, 0, dp);
    }
};