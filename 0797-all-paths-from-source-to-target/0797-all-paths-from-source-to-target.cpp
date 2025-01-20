class Solution {
    vector<int> path;
    vector<vector<int>> result;
public:
    void dfs(const vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i], n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return result;
    }
};