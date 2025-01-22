class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j});
                    result[i][j] = 0;
                }
            }
        }
        int distance = 1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> pos = que.front();
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int nextRow = pos.first + dir[i][0];
                    int nextCol = pos.second + dir[i][1];
                    if (nextRow < 0 || nextCol < 0 || nextRow >= m || nextCol >= n) continue;
                    if (result[nextRow][nextCol] != -1) continue;
                    que.push({nextRow, nextCol});
                    result[nextRow][nextCol] = distance;
                }
            }
            distance++;
        }
        return result;
    }
};