class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        // Check if the first node is root
        if (nodes[0][1] >= 0) {
            return false;
        }
        unordered_map<int, vector<int>> adjList;
        for (const auto& v : nodes) {
            adjList[v[1]].push_back(v[0]);
        }
        int index = 0;
        return dfs(index, nodes[0][0], nodes, adjList);
    }
private:
    bool dfs(int& index, int node, vector<vector<int>>& nodes, unordered_map<int, vector<int>>& adjList) {
        // Check if the node is the correct node while in preorder traversal
        if (index >= nodes.size() || nodes[index][0] != node) {
            return false;
        }
        index++;
        // If the current node is just a leaf node
        if (adjList.find(node) == adjList.end()) {
            return true;
        }
        // Traverse each child connecting to the current node
        for (int child : adjList[node]) {
            if (!dfs(index, child, nodes, adjList)) {
                return false;
            }
        }
        return true;
    }
};