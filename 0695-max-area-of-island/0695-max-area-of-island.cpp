class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    void dfs(vector<vector<int>>& grid, int& count, int row, int col) {
        count++;
        grid[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dir[i][0];
            int nextCol = col + dir[i][1];
            if (nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) continue;
            if (grid[nextRow][nextCol] == 0) continue;
            dfs(grid, count, nextRow, nextCol);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count;
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, count, i, j);
                    maxArea = max(count, maxArea);
                }
            }
        }
        return maxArea;
    }
};