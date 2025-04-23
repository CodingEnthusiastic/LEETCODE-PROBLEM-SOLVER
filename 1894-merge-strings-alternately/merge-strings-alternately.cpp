class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans;
        int ptr1=0;
        int ptr2=0;
        while(ptr1<word1.size()&&ptr2<word2.size())
        {
            if(ptr1==ptr2)
            {
                ans=ans+word1[ptr1];
                ptr1++;
            }
            else
            {
                ans=ans+word2[ptr2];
                ptr2++;
            }
        };
        while(ptr1!=word1.size())
        {
            ans=ans+word1[ptr1];
            ptr1++;
        };
        while(ptr2!=word2.size())
        {
            ans=ans+word2[ptr2];
            ptr2++;
        };
        return ans;
    }
};