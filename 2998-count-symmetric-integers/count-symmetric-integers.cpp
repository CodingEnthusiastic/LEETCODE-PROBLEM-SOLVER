class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string s=to_string(i);
            if(s.size()%2!=0)
                continue;
            int n=s.size()/2;
            int c1=0,c2=0;
            for(int i=0;i<n;i++)
            {
                c1+=s[i]-'0';
                c2+=s[n+i]-'0';
            };
            if(c1==c2)
                count++;
        };
        return count;
    }
};