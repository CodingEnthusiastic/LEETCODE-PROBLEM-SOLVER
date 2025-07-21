class Solution {
public:
    string makeFancyString(string s) {
        char prev='\0';
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==prev)
            {
                count++;
                if(count==3)
                {
                    count--;
                    s[i]='#';
                }
            }
            else
            {
                count=1;
                prev=s[i];
            }
        }
        string res=s;
        s="";
        int distance=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!='#')
            {
                s.push_back(res[i]);
            
            }
            //swap(s[i],s[distance+i]);
        }

        return s;
    }
};