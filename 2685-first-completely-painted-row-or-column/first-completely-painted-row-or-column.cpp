class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> cell_pos;
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cell_pos[mat[i][j]] = {i, j};
            }
        }
        vector<int> row_paint(m, 0);
        vector<int> col_paint(n, 0);
        for (int idx = 0; idx < arr.size(); ++idx) 
        {
            auto [row, col] = cell_pos[arr[idx]];
            row_paint[row]++;
            col_paint[col]++;
            if (row_paint[row] == n || col_paint[col] == m)
             {
                return idx;
            }
        }

            return -1;

        }
};