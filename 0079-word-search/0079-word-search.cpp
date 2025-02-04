class Solution {
public:
    const vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word, int index) {
        if (index == word.size() - 1) return true;
        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= board.size() || newCol >= board[0].size()) continue;
            if (visited[newRow][newCol]) continue;
            if (board[newRow][newCol] == word[index + 1]) {
                bool result = dfs(board, visited, newRow, newCol, word, index + 1);
                if (result) return true;
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    bool found = dfs(board, visited, i, j, word, 0);
                    if (found) return true;
                }
            }
        }
        return false;
    }
};