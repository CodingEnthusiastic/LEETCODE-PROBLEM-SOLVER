class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long counter=0;
        long long prefix=0;
        for(int i=0;i<arr.size();i++)
        {
            prefix+=arr[i];
            counter+=(prefix%2);
        }
        counter+=((arr.size()-counter)*counter)%1000000007;
        return counter%1000000007;
    }

};