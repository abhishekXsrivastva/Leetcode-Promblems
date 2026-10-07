class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nRow = row + deltaRow[k];
                int nCol = col + deltaCol[k];

                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                   }
            }

        }
        int numberOfMoves = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    numberOfMoves++;
                }
            }
        }
        
        return numberOfMoves;
    }
};