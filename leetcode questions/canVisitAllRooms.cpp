class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int room){
            visited[room] = true;
            for(int key : rooms[room]){
                if(!visited[key]){
                    dfs(key);
                }
            }
        };

        dfs(0);

        for(bool v : visited) {
            if(!v) return false;
        }

        return true;
    }
};
