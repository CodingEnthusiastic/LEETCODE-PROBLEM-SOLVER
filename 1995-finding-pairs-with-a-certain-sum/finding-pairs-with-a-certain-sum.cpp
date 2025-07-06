class FindSumPairs {
public:
    vector<int>arr;
    vector<int>brr;
    map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr=nums1;
        brr=nums2;
        for(int i=0;i<nums2.size();i++)
        {
            mp[brr[i]]++;
        }
    }
    
    void add(int index, int val) {
        
        mp[brr[index]]--;
        if(mp[brr[index]]==0)
        mp.erase(brr[index]);
        brr[index]+=val;
        mp[brr[index]]++;
    }
    
    int count(int tot) {
        int counter=0;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(tot-arr[i])!=mp.end())
            {
                counter+=mp[tot-arr[i]];
            }
        }


        return counter;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */