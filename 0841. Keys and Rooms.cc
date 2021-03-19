class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bitset<1000> locked;

        for (int i = 0; i < rooms.size(); ++i)
            locked[i] = true;

        function<void(int)> dfs = [&](int room) -> void {
            locked[room] = false;

            if (locked.none())
                return;

            for (int i = 0; i < rooms[room].size(); ++i) {
                if (locked[rooms[room][i]])
                    dfs(rooms[room][i]);
            }
        };

        dfs(0);

        return locked.none();
    }
};
