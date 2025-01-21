class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> pos = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int nextRow = pos.first + dir[i][0];
                    int nextCol = pos.second + dir[i][1];
                    if (nextRow < 0 || nextCol < 0 || nextRow >= maze.size() || nextCol >= maze[0].size()) continue;
                    if (maze[nextRow][nextCol] == '+') continue;
                    if (nextRow == maze.size() - 1 || nextCol == maze[0].size() - 1 || nextRow == 0 || nextCol == 0) return steps + 1;
                    maze[nextRow][nextCol] = '+';
                    que.push({nextRow, nextCol});
                }
            }
            steps++;
        }
        return -1;
    }
};