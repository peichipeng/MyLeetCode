class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        if (freshOranges == 0) return 0;
        int min = -1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> pos = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int nextRow = pos.first + dir[i][0];
                    int nextCol = pos.second + dir[i][1];
                    if (nextRow < 0 || nextCol < 0 || nextRow >= m || nextCol >= n) continue;
                    if (grid[nextRow][nextCol] == 0 || grid[nextRow][nextCol] == 2) continue;
                    grid[nextRow][nextCol] = 2;
                    freshOranges--;
                    que.push({nextRow, nextCol});
                }
            }
            min++;
        }
        return freshOranges == 0 ? min : -1;
    }
};