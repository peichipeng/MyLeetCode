class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int index) {
        visited[index] = true;

        for (int i = 0; i < isConnected[index].size(); i++) {
            if (i != index && !visited[i] && isConnected[index][i] == 1) {
                dfs(isConnected, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] == false) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};