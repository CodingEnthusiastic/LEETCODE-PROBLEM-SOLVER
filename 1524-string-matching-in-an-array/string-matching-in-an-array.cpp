class Solution {
public:
    bool isSubstring(string &a,string &b)
    {
        for(int i=0;i<=a.size()-b.size();i++)
        {
            string c=a.substr(i,b.size());
            if(c==b)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>result;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(words[j].size() > words[i].size())
                {
                    continue;
                }
                if(isSubstring(words[i],words[j])==true)
                {
                    result.push_back(words[j]);
                }
            }
        }
        //clean result array
        for(int i=0;i<result.size();i++)
        {
            for(int j=i+1;j<result.size();j++)
            {
                if(result[i]==result[j])
                {
                    result[j]="";
                }
            }
        }
        vector<string>r;
        for(int i=0;i<result.size();i++)
        {
            if(result[i]!="")
            {
                r.push_back(result[i]);
            }
        }
        return r;
    }
};