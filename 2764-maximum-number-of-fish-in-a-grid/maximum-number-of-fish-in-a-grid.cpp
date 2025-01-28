class Solution {
public:
    int func(int m, int n, vector<vector<int>>& grid) {
        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] == 0) 
        {
            return 0;
        }
        int fish = grid[m][n];
        grid[m][n] = 0; 
        fish += func(m - 1, n, grid);
        fish += func(m + 1, n, grid);
        fish += func(m, n - 1, grid);
        fish += func(m, n + 1, grid);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxFish = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, func(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
