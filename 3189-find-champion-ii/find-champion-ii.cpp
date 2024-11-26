class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>inward(n,0);
        for(int i=0;i<edges.size();i++)
        {
            inward[edges[i][1]]++;
        }
        int winner=n;
        for(int i=0;i<n;i++)
        {
            if(inward[i]==0)
            {
                if(winner==n)
                {
                    winner=i;
                }
                else
                {
                    return -1;
                }
            }
        }

        if(winner==n)
        {
            return -1;
        }
        return winner;
    }
};