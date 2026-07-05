class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int> , int>> q;
        int freshCount = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int minutes = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            minutes = max(minutes, time);
            q.pop();

            for(int k = 0; k < 4; k++){
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    freshCount--;
                    q.push({{nrow, ncol}, time+1});
                   }
            }
        }
        return freshCount == 0 ? minutes : -1;
    }
};