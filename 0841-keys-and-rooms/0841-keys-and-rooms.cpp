class Solution {
private:
    int roomsVisited = 0;
    void dfs(vector<vector<int>>& rooms, int roomNum, vector<bool>& visited) {
        visited[roomNum] = true;
        roomsVisited++;

        for (int i = 0; i < rooms[roomNum].size(); i++) {
            int nextRoom = rooms[roomNum][i];
            if (visited[nextRoom]) continue;
            dfs(rooms, nextRoom, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        return roomsVisited == rooms.size();
    }
};