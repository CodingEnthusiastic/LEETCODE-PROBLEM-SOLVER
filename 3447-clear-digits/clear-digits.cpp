class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        };
        string ans;
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        };
        for(int i=0;i<ans.size()/2;i++)
        {
            char t=ans[i];
            ans[i]=ans[ans.size()-i-1];
            ans[ans.size()-i-1]=t;
        }
        return ans;
    }
};