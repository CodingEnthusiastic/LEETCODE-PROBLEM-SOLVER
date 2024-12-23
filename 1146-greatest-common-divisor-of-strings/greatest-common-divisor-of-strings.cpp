class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
        {
            return "";
        }
        int a=str1.size();
        int b=str2.size();
        while(a>0&&b>0)
        {
            if(a>b)
            {
                a=a%b;
            }
            else
            {
                b=b%a;
            }
        }
        cout<<a<<b;
        if(a==0)
        {
            return str2.substr(0,b);
        }
        return str1.substr(0,a);
    }
};