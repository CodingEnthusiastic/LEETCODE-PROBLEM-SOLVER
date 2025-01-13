class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=3)
            {
                int counter=freq[i]-1;
                counter=counter/2;
                ans+=(counter*2);
            }
        }
        return s.size()-ans;
    }
};