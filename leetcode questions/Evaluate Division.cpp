class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0 / val;
        }

        vector<double> results;
        for (const auto& query : queries) {
            string C = query[0];
            string D = query[1];
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double result = dfs(C, D, graph, visited);
            results.push_back(result);
        }
        return results;
    }

    double dfs(const string& current, const string& target, unordered_map<string, unordered_map<string, double>>& graph,        unordered_set<string>& visited) {
        if (current == target) return 1.0;
        visited.insert(current);
        for (const auto& neighbor : graph[current]) {
            const string& next = neighbor.first;
            if (visited.find(next) != visited.end()) continue;
            double res = dfs(next, target, graph, visited);
            if (res != -1.0) {
                return res * neighbor.second;
            }
        }
        return -1.0;
    }
};
