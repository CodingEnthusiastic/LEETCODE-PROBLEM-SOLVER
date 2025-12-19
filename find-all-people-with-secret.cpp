class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& edges, int fP) {
        vector<vector<array<int,2>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[2],it[1]});
            adj[it[1]].push_back({it[2],it[0]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        pq.push({0,fP});
        pq.push({0,0});
        dist[0]=0;
        dist[fP]=0;
        
      
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int tim= cur[0];
            int node= cur[1];
            
            if(tim>dist[node]) continue;
            for(auto it:adj[node])
            {
                int nei= it[1];
                int reqtime=it[0];
                if(tim<=reqtime)
                {
                    
                    if(reqtime<dist[nei])
                    {
                        dist[nei]=reqtime;
                        pq.push({reqtime,nei});
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=INT_MAX) 
            ans.push_back(i);
        }
        
        return ans;
    }
};
