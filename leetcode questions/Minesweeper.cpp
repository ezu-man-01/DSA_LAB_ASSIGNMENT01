class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'E')
                return;

            int mineCount = 0;
            for (auto& [dx, dy] : dirs) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && board[ni][nj] == 'M') {
                    ++mineCount;
                }
            }

            if (mineCount > 0) {
                board[i][j] = '0' + mineCount;
            } else {
                board[i][j] = 'B';
                for (auto& [dx, dy] : dirs) {
                    dfs(i + dx, j + dy);
                }
            }
        };

        dfs(x, y);
        return board;
    }
};
