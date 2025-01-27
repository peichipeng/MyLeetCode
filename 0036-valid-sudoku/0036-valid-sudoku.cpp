class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> blocks(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                char num = board[i][j];
                if (rows[i].find(num) != rows[i].end()) return false;
                if (cols[j].find(num) != cols[j].end()) return false;
                int index = j / 3 + (i / 3) * 3;
                if (blocks[index].find(num) != blocks[index].end()) return false;
                rows[i].insert(num);
                cols[j].insert(num);
                blocks[index].insert(num);
            }
        }
        return true;
    }
};