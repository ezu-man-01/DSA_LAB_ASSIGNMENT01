class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j = 0];
                    q.push({i, j});
                }
            }
        }

        if(q.empty() || q.size() == n * n){
            return -1;
        }

        int maxDist = -1;
        int dirs[4][2] = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(auto& dir : dirs){
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && ni < n && nj >=0 && nj < n && dist[ni][nj] > dist[i][j] +1){
                    dist[ni][nj] = dist[i][j] + 1;
                    maxDist = max(maxDist, dist[ni][nj]);
                    q.push({ni, nj});
                }
            }
        }
        return maxDist;
    }
};