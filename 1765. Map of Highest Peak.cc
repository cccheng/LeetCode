class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int nr_row = isWater.size();
        int nr_col = isWater.back().size();
        vector<vector<int>> result(nr_row, vector<int>(nr_col, 1000000));
        queue<tuple<int,int,int>> que;
        
        function<void(void)> bfs = [&](void) -> void {
            vector<vector<bool>> visited(nr_row, vector<bool>(nr_col, false));
            
            while (!que.empty()) {
                int r = get<0>(que.front());
                int c = get<1>(que.front());
                int h = get<2>(que.front());
                que.pop();
                
                if (r < 0 || c < 0 || r >= nr_row || c >= nr_col)
                    continue;
                
                if (visited[r][c])
                    continue;
                visited[r][c] = true;
                
                if (isWater[r][c] && h != 0)
                    continue;
                
                if (result[r][c] > h) {
                    result[r][c] = h;
                
                    que.push({r-1, c, h+1});
                    que.push({r+1, c, h+1});
                    que.push({r, c-1, h+1});
                    que.push({r, c+1, h+1});
                }
            }
        };
        
        for (int row = 0; row < nr_row; row++)
            for (int col = 0; col < nr_col; col++) {
                if (isWater[row][col])
                    que.push({row,col,0});
            }
        bfs();
        
        return result;
    }
};
