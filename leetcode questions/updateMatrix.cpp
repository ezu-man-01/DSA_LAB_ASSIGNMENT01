class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1},{0,1}};

        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            for(auto[dr, dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(distance[nr][nc] > distance[r][c] + 1){
                        distance[nr][nc] = distance[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return distance;
    }
};
