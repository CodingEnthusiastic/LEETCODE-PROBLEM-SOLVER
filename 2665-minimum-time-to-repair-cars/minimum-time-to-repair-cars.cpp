class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        int n=ranks.size();
        long long start=1;
        
        long long answer=1000000000000000ll;
        long long end=answer;
        while(start<=end)
        {
            long long mid=start+((end-start)/2);
            long long curr=0;
            long long rem=mid;
            bool flag=0;
            for(int i=0;i<n;i++)
            {
                 long long d=rem/ranks[i];
                 d=(long long)sqrt(d);
                 curr=curr+d;
                if(curr>=cars)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                answer=min(mid,answer);
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return answer;
    }
};