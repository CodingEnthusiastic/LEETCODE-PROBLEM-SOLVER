class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>res;
        string temp="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
            {
                res.push_back(temp);
                temp="";
            }
            else
            {
                temp=temp+sentence[i];
            }
        }
        res.push_back(temp);
        for(int i=0;i<res.size();i++)
        {
            string temp="";
            if(res[i].size() < searchWord.size())
            {
                continue;
            }
            for(int j=0;j<searchWord.size();j++)
            {
                temp=temp+res[i][j];
            }
            if(temp==searchWord)
            {
                return i+1;
            }
        }

        return -1;
    }
};