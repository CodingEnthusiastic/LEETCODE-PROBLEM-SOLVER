
class Solution {
public:
    void func(int row, int n, vector<string>& board, vector<vector<string>>& result,
vector<bool>& colUsed, vector<bool>& leftDiagUsed, vector<bool>& rightDiagUsed) {
        // jab saari raani aagyi game main , ruk jao
        if(row >= n) 
        {
            result.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) 
        {
            if (!colUsed[col] && !leftDiagUsed[row - col + n - 1] && !rightDiagUsed[row + col]) 
            {
                board[row][col] = 'Q'; 
                colUsed[col] = leftDiagUsed[row - col + n - 1] = rightDiagUsed[row + col] = true;

                func(row + 1, n, board, result, colUsed, leftDiagUsed, rightDiagUsed);

                board[row][col] = '.';
                colUsed[col] = leftDiagUsed[row - col + n - 1] = rightDiagUsed[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); 

        vector<bool> colUsed(n, false), leftDiagUsed(2 * n - 1, false), rightDiagUsed(2 * n - 1, false);

        func(0, n, board, result, colUsed, leftDiagUsed, rightDiagUsed);

        return result;
    }
};

