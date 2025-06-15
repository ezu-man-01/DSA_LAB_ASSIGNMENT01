class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        area++;

                        for (auto [dx, dy] : directions) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                                q.push({nx, ny});
                                grid[nx][ny] = 0;
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
