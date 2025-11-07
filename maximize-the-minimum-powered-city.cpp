#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stations[i];
        }
        
        vector<long long> power(n, 0);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }
        
        long long left = 0ll, right = 1e15;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (canAchieve(power, r, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    bool canAchieve(vector<long long>& power, int r, long long k, long long target) {
        int n = power.size();
        vector<long long> add(n, 0);
        long long currAdd = 0, used = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > r) {
                currAdd -= add[i - r - 1];
            }
            
            if (power[i] + currAdd < target) {
                long long need = target - (power[i] + currAdd);
                if (need > k - used) return false;
                
                int pos = min(n - 1, i + r);
                add[pos] += need;
                currAdd += need;
                used += need;
            }
        }
        return true;
    }
};
