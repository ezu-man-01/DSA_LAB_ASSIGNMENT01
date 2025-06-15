class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q; 
        q.push({0, 1});
        unordered_set<string> visited;
        visited.insert("0,1");
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [pos, speed] = q.front();
                q.pop();

                if (pos == target) {
                    return steps;
                }

                int new_pos = pos + speed;
                int new_speed = speed * 2;
                string key = to_string(new_pos) + "," + to_string(new_speed);
                if (visited.find(key) == visited.end() && abs(new_pos) < 2 * target) {
                    visited.insert(key);
                    q.push({new_pos, new_speed});
                }

                new_speed = speed > 0 ? -1 : 1;
                key = to_string(pos) + "," + to_string(new_speed);
                if (visited.find(key) == visited.end() && abs(pos) < 2 * target) {
                    visited.insert(key);
                    q.push({pos, new_speed});
                }
            }
            steps++;
        }

        return -1;
    }
};