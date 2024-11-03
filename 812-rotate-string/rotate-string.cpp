class Solution {
public:
    bool rotateString(string s, string goal) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s.size()!=goal.size())
        {
            return false;
        }
        vector<int>starts;
        int start=0;
        bool flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==goal[0])
            {
                starts.push_back(i);
                flag=1;
                //break;
            }
        }
        if(flag==0)
        {
            return false;
        }
        int n=goal.size();
        for(int j=0;j<starts.size();j++)
        {
            int count=0;
            start=starts[j];
            for(int i=0;i<n;i++)
            {
                if(s[(start+i)%n]==goal[i])
                {
                    count++;
                }
                
            }
            if(count==n)
            {
                return true;
            }
        }
        return false;
    }
};