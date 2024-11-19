class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        long long int sum=0;
        unordered_set<int>np;
        long long int maxSum=0;
        for(int i=0;i<k;i++)
        {
            mp[arr[i]]++;
            sum=sum+arr[i];
            if(mp[arr[i]]>=2)
            {
                np.insert(arr[i]);
            }
            
        }
        if(np.size()==0)
        {
            maxSum=max(sum,maxSum);
        }
        int flag=0;
        
        
        for(int i=k;i<arr.size();i++)
        {
            flag=0;
            mp[arr[i-k]]=mp[arr[i-k]]-1;
            sum=sum-arr[i-k];
            if(mp[arr[i-k]]<2)
            {
                np.erase(arr[i-k]);
            }
            sum=sum+arr[i];
            mp[arr[i]]++;
            if(mp[arr[i]]>=2)
            {
                np.insert(arr[i]);
            }
            

            if(np.size()>0)
            {
                flag=1;
            }
            if(flag==0)
            {
                maxSum=max(sum,maxSum);
            }
        }

        return maxSum;
    }
};