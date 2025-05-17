class Solution {
public:
bool flag=false;
    bool issafe(char num,vector<vector<char>>& board,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==num)
            return false;
            if(board[i][col]==num)
            return false;
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; i++) 
        {
            for (int j = startCol; j < startCol + 3; j++) 
            {
                if (board[i][j] == num)
                 return false;
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board,int row,int col)
    {
        if(row==9)
        {
            flag=true;
            return;
        }
        int i=row;
        int j=col;
        if(board[i][j]!='.')
        {
            if(j<8)
            solve(board,i,j+1);
            else
            solve(board,i+1,0);
            return;
        }
        for(char k='1';k<='9';k++)
        {
            if(issafe(k,board,i,j)==true)
            {
                board[i][j]=k;
                if(j<8)
                solve(board,i,j+1);
                else
                solve(board,i+1,0);
                if(flag)
                {
                    return;
                }
                board[i][j]='.';
            }
        }
    }
        
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};