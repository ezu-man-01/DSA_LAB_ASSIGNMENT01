class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<pair<int,int>> directions = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };

        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        grid[0][0] = 1;

        while (!q.empty()){
            auto [row,col,length] = q.front();
            q.pop();

            if(row == n-1 && col == n-1) return length;

            for(auto [dr,dc]: directions){
                int r = row + dr, c = col + dc;

                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0){
                    q.push({r,c,length + 1});
                    grid[r][c] = 1;
                }
            }
        }

        return -1;
    }
};
