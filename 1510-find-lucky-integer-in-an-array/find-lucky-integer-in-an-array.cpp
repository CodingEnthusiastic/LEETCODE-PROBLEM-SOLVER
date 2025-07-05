class Solution {
public:
    int findLucky(vector<int>& arr) {
       map<int,int>mp;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           mp[arr[i]]++;
       }
       int maxi=-1;
       for(auto i=mp.begin();i!=mp.end();i++)
       {
            if(i->first==i->second)
            maxi=i->first;
       }
        return maxi;
    }
};