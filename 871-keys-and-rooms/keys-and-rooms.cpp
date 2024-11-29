class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>visited(rooms.size(),0);
        q.push(0);
        while(q.size()!=0)
        {
            int index=q.front();
            visited[index]=1;
            q.pop();
            for(int i=0;i<rooms[index].size();i++)
            {
                if(visited[rooms[index][i]]==1)
                {
                    continue;
                }
                q.push(rooms[index][i]);
            }
        }
        for(int i=0;i<rooms.size();i++)
        {
            if(visited[i]==0)
            {
                return 0;
            }
        }

        return 1;
    }
};