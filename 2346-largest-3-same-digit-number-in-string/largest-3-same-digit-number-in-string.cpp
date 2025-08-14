class Solution {
public:
    string largestGoodInteger(string num) {
        int curr=-1;
        vector<int>st(10,0);
        for(int i=0;i<3;i++)
        {
            st[num[i]-'0']++;
        }
        if(st[num[2]-'0']==3)
        {
            curr=num[2]-'0';
        }
        for(int i=3;i<num.size();i++)
        {
            st[num[i-3]-'0']--;
            st[num[i]-'0']++;
            if(st[num[i]-'0']==3)
            {
                curr=max(curr,num[i]-'0');
            }

        }
        string t="";
        if(curr==-1)
        {
            return "";
        }
        else
        {
            t="";
            for(int i=0;i<3;i++)
            t=t+to_string(curr);
        }



        return t;
    }
};