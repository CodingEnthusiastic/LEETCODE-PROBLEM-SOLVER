using ll=long long;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<int>arr=nums;
        
        int maxi=0ll;
        vector<int>brr(100001,0ll);
        for(int i=0;i<n;i++)
        {
            brr[arr[i]]++;
        }
        int m=100000;
        // int maxi=mini;
        int left=0;
        int right=100000;
        while(left<=right)
        {
            while(left<=m&&brr[left]==0)
            {
                left++;
            }

            while(right>=0&&brr[right]==0)
            {
                right--;
            }
            if(left<=m&&right>=0)
            {

            }
            else
            {
                // cout<<"Breaked here-2";
                break;
            }
            // brr[left]--;
            // brr[right]--;
            if(left>right)
            break;
            if(left==right&&brr[left]<2)
            {
                // cout<<"Breaked here-1";
                break;
            }
            // cout<<left+right<<endl;
            maxi=max(maxi,left+right);

            brr[left]--;
            brr[right]--;
        }


        return (int)maxi;
    }
};
