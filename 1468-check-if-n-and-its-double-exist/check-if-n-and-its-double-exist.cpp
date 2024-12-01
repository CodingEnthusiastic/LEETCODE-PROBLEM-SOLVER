class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]==2*arr[i])
                {
                    return true;
                }
                else if((arr[j]==0.5*arr[i])&&(arr[i]<0)&&(arr[j]<0))
                    return true;
            }
        }
        return false;
    }
};