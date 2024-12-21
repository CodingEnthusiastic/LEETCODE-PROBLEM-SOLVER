class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>result;
        result.push_back(0);
        for(int i=0;i<gain.size();i++)
        {
            result.push_back(result[result.size()-1]+gain[i]);
        }
        int maxi=0;
        for(int i=1;i<result.size();i++)
        {
            maxi=max(result[i],maxi);
        }
        return maxi;
    }
};