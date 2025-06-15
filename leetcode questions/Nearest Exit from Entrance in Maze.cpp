class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
                    !(x == entrance[0] && y == entrance[1])) {
                    return steps;
                    }

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};