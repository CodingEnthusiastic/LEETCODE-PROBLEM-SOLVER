class Solution {
public:
    int isMatch(string &a,string &b)
    {
        string prefix=b.substr(0,a.size());
        string suffix=b.substr(b.size()-a.size(),a.size());
        if(a==prefix&&a==suffix)
        {
            return 1;
        }
        return 0;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int counter=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[i].size() > words[j].size())
                {
                    continue;
                }
                counter=counter+isMatch(words[i],words[j]);
            }
        }

        return counter;
    }
};