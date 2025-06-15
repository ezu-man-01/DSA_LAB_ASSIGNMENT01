class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        if(dead.count("0000")) return -1;

        q.push({"0000", 0});
        visited.insert("0000");

        while(!q.empty()){
            auto[current, steps] = q.front();
            q.pop();

            if(current == target) return steps;

            for(int i = 0; i < 4; i++){
                char c = current[i];

                string up = current;
                up[i] = (c == '9') ? '0' : c + 1;

                string down = current;
                down[i] = (c == '0') ? '9' : c - 1;

                if(!dead.count(up) && !visited.count(up)){
                    q.push({up, steps + 1});
                    visited.insert(up);
                }
                if(!dead.count(down) && !visited.count(down)){
                    q.push({down, steps + 1});
                    visited.insert(down);
                }
            }
        }
        return -1;
    }
};
