class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nr_row = grid.size();
        int nr_col = grid.back().size();
        vector<vector<bool>> visited(nr_row, vector<bool>(nr_col, false));
        queue<tuple<int,int,int>> bfs; // <row,col,step>

        if (grid[0][0] == 0) {
            bfs.push({0,0,1});
            visited[0][0] = true;
        }

        while (!bfs.empty()) {
            auto [row, col, step] = bfs.front();
            bfs.pop();

            if (row == nr_row - 1 && col == nr_col - 1)
                return step;

            int row_dir[] = {-1, 0, 1};
            int col_dir[] = {-1, 0, 1};
            for (int r = 0; r <= 2; r++)
                for (int c = 0; c <= 2; c++) {
                    int nr = row + row_dir[r];
                    int nc = col + col_dir[c];
                    if (nc < 0 || nr < 0 || nc >= nr_col || nr >= nr_row)
                        continue;
                    if (visited[nr][nc])
                        continue;
                    if (grid[nr][nc] == 1)
                        continue;
                    bfs.push({nr, nc, step+1});
                    visited[nr][nc] = true;
                }
        }

        return -1;
    }
};
