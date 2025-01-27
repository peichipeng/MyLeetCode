class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    void dfs(vector<vector<int>>& grid, vector<long long>& arr, int row, int col) {
        arr[0] += grid[row][col];
        arr[1]++;
        grid[row][col] = -1;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid.size()) continue;
            if (grid[newRow][newCol] == -1) continue;
            dfs(grid, arr, newRow, newCol);
        }
    }
    long long sumRemoteness(vector<vector<int>>& grid) {
        long long total = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    total += grid[i][j];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) continue;
                vector<long long> arr(2, 0);
                // arr[0] = sum of reachable cells
                // arr[1] = count of reachable cells
                dfs(grid, arr, i, j);
                ans += (total - arr[0]) * arr[1];
            }
        }
        return ans;
    }
};