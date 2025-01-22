class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> result = {
            {1},
            {1, 1}
        };
        if (numRows == 2) return result;
        
        for (int i = 2; i < numRows; i++) {
            vector<int> cur = {1};
            for (int j = 0; j < result[i - 1].size() - 1; j++) {
                cur.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            cur.push_back(1);
            result.push_back(cur);
        }
        return result;
    }
};