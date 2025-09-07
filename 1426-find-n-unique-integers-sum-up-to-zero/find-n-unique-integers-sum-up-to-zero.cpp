class Solution {
public:
    vector<int> sumZero(int n) {
        int m=n/2;
        vector<int>arr;
        for(int i=m;arr.size()<n;i--)
        {
            if(i==0)
            arr.push_back(0);
            else
            {
                arr.push_back(i);
                arr.push_back(-i);
            }
        }

        return arr;
    }
};