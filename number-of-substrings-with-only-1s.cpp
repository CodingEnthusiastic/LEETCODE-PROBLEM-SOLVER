using ll=long long;
class Solution {
public:
    int numSub(string s) {
        vector<long long>palin(100001,0ll);
        palin[1]=1;
        palin[2]=3;
        for(ll i=3;i<100001;i++)
        {
            palin[i]=(palin[i-1]+i);
            if(palin[i]>=1000000007ll)
            {
                palin[i]=palin[i]%1000000007ll;
            }

        }



        long long ans=0ll;
        int curr=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                curr++;
            else
            {
                ans+=palin[curr];
                ans=ans%1000000007ll;
                curr=0;
            }

            cout<<curr;
        }

        cout<<'\n'<<palin[curr]<<' '<<curr;
        ans+=palin[curr];
        ans=ans%1000000007ll;
        return ans;
    }
};
