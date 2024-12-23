class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=INT_MIN;
        for(int i=0;i<candies.size();i++)
        {
            maximum=max(maximum,candies[i]);
        }
        vector<bool>result(candies.size(),false);
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >= maximum)
            {
                result[i]=true;
            }
        }
        return result;
    }
};