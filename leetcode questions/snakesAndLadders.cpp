class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattened(n * n + 1);
        int index = 1;
        bool leftToRight = true;

        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    flattened[index++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    flattened[index++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        q.push(1);
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();

                if (current == n * n) {
                    return moves;
                }

                for (int j = 1; j <= 6 && current + j <= n * n; ++j) {
                    int next = current + j;
                    if (flattened[next] != -1) {
                        next = flattened[next];
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
