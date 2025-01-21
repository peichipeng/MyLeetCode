class Solution {
public:
    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& visited, double& ans, double temp) {
        if (visited.find(node) != visited.end()) return;

        visited.insert(node);
        if (node == dest) {
            ans = temp;
            return;
        }

        for (auto ne : gr[node]) {
            dfs(ne.first, dest, gr, visited, ans, temp * ne.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr;
        vector<double> finalAns;

        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];
            
            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1.0 / value;
        }

        for (auto query : queries) {
            string dividend = query[0];
            string divisor = query[1];

            if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()) {
                finalAns.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double ans = -1, temp = 1.0;
                dfs(dividend, divisor, gr, visited, ans, temp);
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }
};