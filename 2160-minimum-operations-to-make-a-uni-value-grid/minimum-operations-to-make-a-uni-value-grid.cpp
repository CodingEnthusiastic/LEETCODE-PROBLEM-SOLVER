class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int result = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                arr.push_back(grid[row][col]);
            }
        }

        int length = arr.size();
        sort(arr.begin(),arr.end());
        int finalCommonNumber = arr[length / 2];

        for (int number : arr) {
            
            if (number % x != finalCommonNumber % x) 
            return -1;
            
            result += abs(finalCommonNumber - number) / x;
        }

        return result;
    }
};