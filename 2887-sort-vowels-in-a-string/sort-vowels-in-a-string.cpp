class Solution {
public:
    string sortVowels(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        int count=0;
        string vowel;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
            {
                lower[s[i]-'a']++;
                s[i]='#';
                count++;
            }
            if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U'))
            {
                upper[s[i]-'A']++;
                s[i]='#';
                count++;
            }
        }
        for(int i=0;i<26;i++)
        {
            while(upper[i]!=0)
            {
                vowel.push_back(i+'A');
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++)
        {
            while(lower[i]!=0)
            {
                vowel.push_back(i+'a');
                lower[i]--;
            }
        }
        cout<<vowel;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                s[i]=vowel[j];
                j++;
            }
        }
        return s;
    }
};