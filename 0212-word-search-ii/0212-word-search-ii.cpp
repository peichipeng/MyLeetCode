class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;

    TrieNode() : word("") {}
};

class Solution {
private:
    // Intance variables (so there are underscores to help differentiate them)
    vector<vector<char>> _board;
    vector<string> _result;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Step 1 : construct the trie
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char letter : word) {
                if (node->children.find(letter) != node->children.end()) {
                    // this corresponds to the TrieNode of the letter
                    node = node->children[letter];
                } else {
                    TrieNode* newNode = new TrieNode();
                    node->children[letter] = newNode;
                    node = newNode;
                }
            }
            node->word = word; // store words in Trie
        }

        this->_board = board;
        // Step 2 : backtracking starting for each cell in the board
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (root->children.find(board[row][col]) != root->children.end()) {
                    backtracking(row, col, root);
                }
            }
        }
        return this->_result;
    }
private:
    void backtracking(int row, int col, TrieNode* parent) {
        char letter = this->_board[row][col];
        TrieNode* currNode = parent->children[letter];

        // check if there is any match
        if (currNode->word != "") {
            this->_result.push_back(currNode->word);
            currNode->word = ""; // prevent duplicate entries
        }

        // mark the current letter before the EXPLORATION
        this->_board[row][col] = '#';

        // explore neighbor cells
        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowOffset[i];
            int newCol = col + colOffset[i];
            if (newRow < 0 || newCol < 0 || newRow >= this->_board.size() || newCol >= this->_board[0].size()) {
                continue;
            }
            if (currNode->children.find(this->_board[newRow][newCol]) != currNode->children.end()) {
                backtracking(newRow, newCol, currNode);
            }
        }

        this->_board[row][col] = letter;

        if (currNode->children.empty()) {
            parent->children.erase(letter);
        }
    }
};