class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int len1=str1.size();
        int len2=str2.size();
        if(len1 < len2)
        {
            return 0;
        }
        int index=0;
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]==str2[index]||str1[i]==str2[index]-1||(str1[i]=='z'&&str2[index]=='a'))
            {
                index++;
            }
            if(index==len2)
            {
                break;
            }
        }
        return index==len2;
    }
};