class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>sums(10000,0);
        map<int,int>mp;
        for(int i=1;i<n+1;i++)
        {
            int sum=0;
            int temp=i;
            while(temp>0)
            {
                sum+=(temp%10);
                temp=temp/10;
            }
            
            
            sums[sum]++;
        }
        sort(sums.rbegin(),sums.rend());
        int lar=sums[0];
        int t=0;
        for(int i=0;i<sums.size();i++)
        {
            if(lar==sums[i])
            t++;
        }
        return t;


    }
};