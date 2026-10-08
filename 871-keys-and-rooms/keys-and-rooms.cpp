class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> visited(rooms.size(), false);

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        for (bool x : visited) {
            if (!x)
                return false;
        }
        return true;
    }
};