class Solution {
public:
    void dfs(vector<vector<int>>& grid, int& count, int row, int col) {
        count++;
        grid[row][col] = 0;

        for (int i = row + 1; i < grid.size(); i++) {
            if (grid[i][col] == 1) {
                dfs(grid, count, i, col);
            }
        }
        for (int i = col + 1; i < grid[0].size(); i++) {
            if (grid[row][i] == 1) {
                dfs(grid, count, row, i);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int servers = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, count, i, j);
                    if (count > 1) servers += count;
                }
            }
        }
        return servers;
    }
};