class Solution {
private:
    long long INF = 1e18;
    long long solve(int i,string& src,string& tgt,unordered_map<string,int>& mp,vector<vector<long long>>& dist,vector<long long>& dp){
        int n = src.length();
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        long long ans = INF;
        if(src[i] == tgt[i])ans = solve(i+1,src,tgt,mp,dist,dp);
        for (auto const &p : mp) {
            const string &s1 = p.first;
            int u = p.second;
            int len = (int)s1.size();
            if (i + len > n) continue;
            if (src.compare(i, len, s1) != 0) continue;

            string tar = tgt.substr(i, len);
            auto it = mp.find(tar);
            if (it == mp.end()) continue;
            int v = it->second;

            if (dist[u][v] != INF) {
                ans = min(ans, dist[u][v] + solve(i + len, src, tgt, mp, dist, dp));
            }
        }
        return dp[i] = ans;
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,int> mp;
        int ct = 0;
        for(int i=0;i<original.size();i++){
            if(mp.find(original[i]) == mp.end())mp[original[i]] = ct++;
            if(mp.find(changed[i]) == mp.end())mp[changed[i]] = ct++;
        }
        vector<vector<long long>> dist(ct,vector<long long>(ct,INF));
        for(int i=0;i<ct;i++)dist[i][i] = 0;
        for(int i=0;i<original.size();i++){
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v],1ll*cost[i]);
        }
        for(int k=0;k<ct;k++){
            for(int i=0;i<ct;i++){
                for(int j=0;j<ct;j++){
                    if(dist[i][k] != INF && dist[k][j] != INF)dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<long long> dp(source.size(),-1);
        long long ans = solve(0,source,target,mp,dist,dp);
        if(ans == INF)return -1;
        return ans;
    }
};
