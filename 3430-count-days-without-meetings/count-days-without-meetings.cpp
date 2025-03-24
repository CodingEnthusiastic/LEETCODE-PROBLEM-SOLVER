class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<pair<int,int>>ap(n);
        for(int i=0;i<n;i++)
        {
            ap[i].first=meetings[i][0];
            ap[i].second=meetings[i][1];
        }
        sort(ap.begin(),ap.end());
        int prev=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=max(0,ap[i].first-prev-1);
            prev=max(ap[i].second,prev);
        }
        res+=max(0,days-prev);
        return res;
    }
};