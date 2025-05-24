class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<vector<int>>dp(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                dp[i][words[i][j]-'a']++;
            }
        }
        int index=x-'a';
        vector<int>arr;
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i][index]>0)
            arr.push_back(i);
        }
        return arr;
    }
};