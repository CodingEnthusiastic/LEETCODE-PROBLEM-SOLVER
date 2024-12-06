class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        // for(int i=0;i<banned.size();i++)
        // {
        //     cout<<banned[i]<<' ';
        // }
        //cout<<endl;
        int index=0;
        int counter=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {

            while(index<banned.size()&&banned[index]<i)
            {
                index++;
            }
            if(sum+i<=maxSum&&index<banned.size()&&banned[index]!=i)
            {
                //cout<<i<<' ';
                sum=sum+i;
                counter++;

            }
            else if(sum+i<=maxSum&&index==banned.size())
            {
                sum=sum+i;
                counter++;
            }
            else if(index<banned.size()&&banned[index]==i)
            {
                continue;
            }
            else
            {
                break;
            }
        }

        return counter;
    }
};