class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) {
                    graph[i].push_back(j);
                }
            }
        }

        int max_detonated = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int detonated = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                detonated++;
                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            max_detonated = max(max_detonated, detonated);
        }

        return max_detonated;
    }
};
