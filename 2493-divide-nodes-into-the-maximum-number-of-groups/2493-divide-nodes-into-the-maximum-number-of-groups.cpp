class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            // Transition to 0-index
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            // Start coloring from uncolored nodes
            colors[node] = 0;
            // If the graph is not bipartite, return -1
            if (!isBipartite(adjList, node, colors)) return -1;
        }

        // Calculate the longest shortest path for each node
        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;

            maxNumberOfGroups += getNumberOfGroupsForComponent(adjList, node, distances, visited);
        }
        return maxNumberOfGroups;
    }
private:
    // Checks if the graph is bipartite starting from the given node
    bool isBipartite(vector<vector<int>>& adjList, int node, vector<int>& colors) {
        for (int neighbor : adjList[node]) {
            if (colors[neighbor] == colors[node]) return false;
            if (colors[neighbor] != -1) continue;
            colors[neighbor] = (colors[node] + 1) % 2;
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        return true;
    }

    // Computes the longest shortest path (height) in the graph starting from the source node
    int getLongestShortestPath(vector<vector<int>>& adjList, int srcNode, int n) {
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        while (!que.empty()) {
            int numOfNodesInLayer = que.size();
            for (int i = 0; i < numOfNodesInLayer; i++){
                int curNode = que.front();
                que.pop();

                for (int neighbor : adjList[curNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    que.push(neighbor);
                }
            }
            distance++;
        }
        return distance;
    }

    int getNumberOfGroupsForComponent(vector<vector<int>>& adjList, int node, vector<int>& distances, vector<bool>& visited) {
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups, getNumberOfGroupsForComponent(adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};