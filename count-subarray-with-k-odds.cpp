class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>v;
        v.push_back(-1);
        for(int i=0;i<n;i++)
        { 
            if(arr[i]&1)v.push_back(i);
        }
        v.push_back(n);
        if(v.size()-2<k)return 0; 
        int ind=k;
        long long ans=0;
        int i=1;
        while(k<v.size()-1)
        { 
            ans+=(v[i]-v[i-1])*(v[k+1]-v[k]);
            i++;
            k++;
        }
        return ans;
    }
};
