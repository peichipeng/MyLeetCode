class Solution {
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    que.push({i, j});
                }
            }
        }
        int height = 1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> pos = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int nextRow = pos.first + dir[i][0];
                    int nextCol = pos.second + dir[i][1];
                    if (nextRow < 0 || nextCol < 0 || nextRow >= m || nextCol >= n) continue;
                    if (isWater[nextRow][nextCol] == 1) continue;
                    result[nextRow][nextCol] = height;
                    isWater[nextRow][nextCol] = 1;
                    que.push({nextRow, nextCol});
                }
            }
            height++;
        }
        return result;
    }
};