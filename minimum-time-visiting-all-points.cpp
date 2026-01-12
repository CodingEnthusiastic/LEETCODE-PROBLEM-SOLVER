class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dist=0;
        pair<int,int>prev={0,0};
        int n=points.size();
        prev.first=points[0][0];
        prev.second=points[0][1];
        for(int i=1;i<n;i++)
        {
            dist+=max(abs(points[i][0]-prev.first),abs(points[i][1]-prev.second));
            prev.first=points[i][0];
            prev.second=points[i][1];
        }
        return dist;
    }
};
