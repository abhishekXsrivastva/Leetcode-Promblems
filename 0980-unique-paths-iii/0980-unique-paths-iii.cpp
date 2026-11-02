class Solution {
public:
    int n, m;
    int res;
    int nonObstacles;
    void uniquePathsIIIHelper(int count, int row, int col,
                              vector<vector<int>>& grid) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;
        if (grid[row][col] == -1)
            return;
        if (grid[row][col] == 2) {
            if (count == nonObstacles) {
                res += 1;
            }
             return;
        }
        int temp = grid[row][col];
        grid[row][col] = -1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = row + delRow[k];
            int ncol = col + delCol[k];
            uniquePathsIIIHelper(count + 1, nrow, ncol, grid);
        }
        grid[row][col] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        res = 0;
        nonObstacles = 0;
        int count = 0;
        int start_x = 0, start_y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    nonObstacles++;
                }
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        nonObstacles += 1;
        uniquePathsIIIHelper(count, start_x, start_y, grid);
        return res;
    }
};