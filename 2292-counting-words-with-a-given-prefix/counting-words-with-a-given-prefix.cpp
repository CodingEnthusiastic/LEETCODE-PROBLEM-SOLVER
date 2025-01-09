class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            string t=words[i].substr(0,m);
            if(t==pref)
            {
                counter++;
            }
        }
        return counter;
    }
};