class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
            int start=i+1;
            int end=arr.size()-1;
            int target=arr[i]*2;
            if(arr[i]<0)
            {
                start=0;
                end=arr.size()-1;
            }
            while(start<=end)
            {
                int mid=start+((end-start)/2);
                if(arr[mid]==target)
                {
                    return 1;
                }
                else if(arr[mid] > target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
        }

        return 0;
    }
};