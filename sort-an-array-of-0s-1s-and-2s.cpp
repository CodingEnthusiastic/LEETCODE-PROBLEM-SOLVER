class Solution {
  public:
    void sort012(vector<int>& a) {
        // code here
        int n=a.size();
        int count0=0;
        int count1=0;
        int count2=0;
        int i=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                count0++;
            else if(a[i]==1)
                count1++;
            else
                count2++;
        };
        i=0;
        while(count0--)
        {
            a[i]=0;
            i++;
        };
        while(count1--)
        {
            a[i]=1;
            i++;
        };
        while(count2--)
        {
            a[i]=2;
            i++;
        };
    }
};
