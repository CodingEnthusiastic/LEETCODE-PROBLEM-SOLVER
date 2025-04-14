class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int counter=0;
        vector<int>brr(3,a);
        brr[1]=b;
        brr[2]=c;
        sort(brr.begin(),brr.end());
        for(int i=0;i<arr.size()-2;i++)
        {
            for(int j=i+1;j<arr.size()-1;j++)
            {
                for(int k=j+1;k<arr.size();k++)
                {
                    int a1=abs(arr[i]-arr[j]);
                    int b1=abs(arr[j]-arr[k]);
                    int c1=abs(arr[i]-arr[k]);
                    if(a1<=a&&b1<=b&&c1<=c)
                    counter++;
                }
            }
        }

        return counter;
    }
};