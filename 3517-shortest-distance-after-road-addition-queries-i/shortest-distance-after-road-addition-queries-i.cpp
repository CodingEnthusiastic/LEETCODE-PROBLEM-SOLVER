class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m=queries.size();

        vector<int>result(m,0);
        //adj [matrix banao
        vector<vector<bool>>adj(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i+1)
                {
                    adj[i][j]=1;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            vector<bool>visited(n,0);
            bool flag=0;
            adj[queries[i][0]][queries[i][1]]=1;
            queue<pair<int,int>>q;
            q.push(make_pair(0,0));
            int index=0;
            while(q.empty()==0)
            {
                int index=q.front().first;
                for(int j=0;j<n;j++)
                {
                    if(q.front().first==n-1)
                    {
                        result[i]=q.front().second;
                        flag=1;
                        break;
                    }
                    if(adj[q.front().first][j]==1&&visited[j]==0)
                    {
                        visited[j]=1;
                        q.push(make_pair(j,q.front().second + 1));
                    }
                }
                if(flag)
                {
                    break;
                }
                q.pop();
            }


            
        }
        return result;
    }
};