class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0,xor2=0;
        if(nums1.size() % 2 == 1)
        {
            for(int i=0;i<nums2.size();i++)
            {
                xor2=xor2^nums2[i];
            }
        }
       // int xor2=0;
        if(nums2.size() % 2 == 1)
        {
            for(int i=0;i<nums1.size();i++)
            {
                xor1=xor1^nums1[i];
            }
        }
        return xor1^xor2;
    }
};