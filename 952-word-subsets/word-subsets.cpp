class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>>freq(words1.size(),vector<int>(26,0));
        for(int i=0;i<words1.size();i++)
        {
            for(int j=0;j<words1[i].size();j++)
            {
                freq[i][words1[i][j]-'a']++;
            }
        }
        vector<int>target(26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int>temp(26,0);
            for(int j=0;j<words2[i].size();j++)
            {
                temp[words2[i][j]-'a']++;
            }
            for(int k=0;k<26;k++)
            {
                target[k]=max(target[k],temp[k]);
            }
        }
        vector<string>result;
        for(int i=0;i<words1.size();i++)
        {
            bool flag=1;
            for(int j=0;j<26;j++)
            {
                if(target[j] <= freq[i][j])
                {
                    continue;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                result.push_back(words1[i]);
            }
        }

        return result;
    }
};