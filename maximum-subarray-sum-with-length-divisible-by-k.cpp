using ll = long long;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {       
        ll sum=0ll;
        ll maxi=LLONG_MIN;
        vector<ll>mini(k, LLONG_MAX / 2);
        mini[(k-1)%k]=0;

        for (int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
            maxi = max(maxi, sum - mini[i % k]);
            mini[i % k] = min(mini[i % k], sum);
        }

        return maxi;
    }
};
