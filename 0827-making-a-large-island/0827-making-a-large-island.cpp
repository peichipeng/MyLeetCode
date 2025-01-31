class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area, int row, int col) {
        area++;
        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid.size()) continue;
            if (visited[newRow][newCol] == true || grid[newRow][newCol] == 0) continue;
            dfs(grid, visited, area, newRow, newCol);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int largestSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int area = 0;
                vector<vector<bool>> visited(n, vector<bool>(n, false));
                dfs(grid, visited, area, i, j);
                largestSize = max(area, largestSize);
            }
        }
        return largestSize;
    }
};