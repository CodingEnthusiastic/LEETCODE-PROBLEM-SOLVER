class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.rbegin(),arr.rend());
        long long ans=0ll;
        for(int i=0;i<k;i++)
        {
            if(arr[i]-i > 0)
            {
                ans+=(arr[i]-i);
            }
            else
            break;
        }

        return ans;

    }
};
