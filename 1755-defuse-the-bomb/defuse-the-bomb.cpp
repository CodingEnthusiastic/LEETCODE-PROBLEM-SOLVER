class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0)
        {
            return ans;
        }
        long long int sum=0;
        if(k<0)
        {
            cout<<"Im less than 0";
            for(int j=0;j<code.size();j++)
            {
                cout<<((j+code.size()-1)%code.size());
                int index=((j+code.size()-1)%code.size());
                cout<<index;
                int temp=-k;
                while(temp>0)
                {
                    if(j==index)
                    {
                        cout<<"Here";
                        break;
                    }
                    sum=sum+code[index];
                    //cout<<index<<"present";
                    index=((index+code.size()-1)%code.size());
                    temp=temp-1;
                }
                // cout<<endl;
                ans[j]=sum;
                sum=0;
            }
        }
        else
        {
            for(int j=0;j<code.size();j++)
            {
                int index=(j+1+code.size())%code.size();
                int temp=k;
                while(temp>0)
                {
                    if(j==index)
                    {
                        break;
                    }
                    ans[j]=ans[j]+code[index];
                    index=(index+1+code.size())%code.size();
                    temp=temp-1;
                }
            }
        }
        return ans;
    }
};