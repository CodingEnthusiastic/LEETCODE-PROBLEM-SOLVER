class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>freq(words.size(),0);
        int prev=0;
        for(int i=0;i<words.size();i++)
        {
            int n=words[i].size();
            //cout<<words[i][0]<<' '<<words[i][n-1]<<endl;
            if((words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')&&(words[i][n-1]=='a'||words[i][n-1]=='e'||words[i][n-1]=='i'||words[i][n-1]=='o'||words[i][n-1]=='u'))
            {
                prev=prev+1;
            }
            freq[i]=prev;
        }
        
        vector<int>solution(queries.size(),0);
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]==0)
            {
                solution[i]=freq[queries[i][1]];
            }
            else
            {
                solution[i]=freq[queries[i][1]]-freq[(queries[i][0])-1];
            }
        }

        return solution;
    }
};