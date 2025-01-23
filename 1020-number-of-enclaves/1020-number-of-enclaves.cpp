class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int count = 0;
    void dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 0;
        count++;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dir[i][0];
            int nextCol = col + dir[i][1];
            if (nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) continue;
            if (grid[nextRow][nextCol] == 0) continue;
            dfs(grid, nextRow, nextCol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) dfs(grid, 0, i);
            if (grid[m - 1][i] == 1) dfs(grid, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][n - 1] == 1) dfs(grid, i, n - 1);
        }
        count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) dfs(grid, i, j);
            }
        }
        return count;
    }
};