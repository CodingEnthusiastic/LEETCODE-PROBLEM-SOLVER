#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int maxN = 0;
    vector<int> queries(t);
    for(int i = 0; i < t; i++) {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    vector<array<int,4>> dp(maxN + 1);
    dp[0] = {1, 0, 0, 0};   

    int nxt[4][2] = {
        {1, 0},  
        {1, 2},   
        {3, 0},    
        {4, 2}    
    };

    for(int i = 1; i <= maxN; i++) {
        array<int,4> cur = {0, 0, 0, 0};
        for(int st = 0; st < 4; st++) 
        {
            long long ways = dp[i-1][st];
            if(!ways) 
            continue;

            int to = nxt[st][0];
            if(to < 4) 
            cur[to] = (cur[to] + ways) % MOD;

            to = nxt[st][1];
            if(to < 4) 
            cur[to] = (cur[to] + ways) % MOD;
        }
        dp[i] = cur;
    }

    for(int n : queries) 
    {
        long long ans = 0;
        for(int s = 0; s < 4; s++) 
        ans = (ans + dp[n][s]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
