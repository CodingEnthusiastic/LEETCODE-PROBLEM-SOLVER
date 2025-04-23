class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                }
            }
        }
        int res=0;
        while(q.size()>0)
        {
            int row=q.top().first;
            int col=q.top().second;
            q.pop();
            if(grid[row][col]=='-')
            {
                // continue;
            }
            else
            {
                res++;
            }
            grid[row][col]='-';
            if(row-1>=0&&grid[row-1][col]=='1')
            {
                grid[row-1][col]='-';
                q.push({row-1,col});
            }
            if(row+1<grid.size()&&grid[row+1][col]=='1')
            {
                grid[row+1][col]='-';
                q.push({row+1,col});
            }
            if(col-1>=0&&grid[row][col-1]=='1')
            {
                grid[row][col-1]='-';
                q.push({row,col-1});
            }
            if(col+1<grid[0].size()&&grid[row][col+1]=='1')
            {
                grid[row][col+1]='-';
                q.push({row,col+1});
            }
        }


        return res;
    }
};