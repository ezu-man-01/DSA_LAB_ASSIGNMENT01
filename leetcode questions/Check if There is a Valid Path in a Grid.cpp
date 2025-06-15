class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {
            {0, -1, 0, 1},  
            {-1, 0, 1, 0},  
            {0, -1, 1, 0}, 
            {0, 1, 1, 0}, 
            {-1, 0, 0, -1}, 
            {-1, 0, 0, 1} 
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i == m - 1 && j == n - 1) return true;
            
            for (int k = 0; k < 2; ++k) {
                int ni = i + dirs[grid[i][j] - 1][2 * k];
                int nj = j + dirs[grid[i][j] - 1][2 * k + 1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    bool canMove = false;
                    for (int l = 0; l < 2; ++l) {
                        int pi = ni + dirs[grid[ni][nj] - 1][2 * l];
                        int pj = nj + dirs[grid[ni][nj] - 1][2 * l + 1];
                        if (pi == i && pj == j) {
                            canMove = true;
                            break;
                        }
                    }
                    if (canMove) {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return false;
    }
};