class Solution {
public:
    int maxScore(string s) {
        int zeroes=0;
        int ones=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ones++;
            }
        }
        int result=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zeroes++;
            }
            else
            {
                ones--;
            }
            result=max(result,zeroes+ones);
        }

        return result;
    }
};