class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        int max1=0;
        int max2=0;
        for(int i=0;i<26;i++)
        {
            if(i==0||i==4||i==8||i==14||i==20)
            {
                max1=max(max1,arr[i]);
            }
            else
            {
                max2=max(max2,arr[i]);
            }
        }

        return max1+max2;
    }
};