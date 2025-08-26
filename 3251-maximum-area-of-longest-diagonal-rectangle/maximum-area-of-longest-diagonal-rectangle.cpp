class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        vector<pair<long long,long long>>arr(n);
        for(int i=0;i<dimensions.size();i++)
        {
            long long a=(long long)dimensions[i][0];
            long long b=(long long)dimensions[i][1];
            a=a*a;
            b=b*b;
            arr[i].first=a+b;
            arr[i].second=dimensions[i][0]*dimensions[i][1];
        }

        sort(arr.rbegin(),arr.rend());

        return arr[0].second;

    }
};