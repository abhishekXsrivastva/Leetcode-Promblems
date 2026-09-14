class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int newRow = q.front().first;
            int newCol = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nRow = newRow + drow[k];
                int nCol = newCol + dcol[k];

                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                   }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int numOfIsland = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    numOfIsland++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return numOfIsland;
        
    }
};

/* 
class Solution {
public:
    void bfs(int startRow, int startCol, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[startRow][startCol] = 1;
        queue<pair<int,int>> q;
        q.push({startRow,startCol});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];
                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       !vis[newRow][newCol] && grid[newRow][newCol] == '1'
                    ){
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                    } 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int isIslandCnt = 0;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                isIslandCnt++;
                bfs(i, j, vis, grid);
                }
            }
        }
        return isIslandCnt;
    }
};
*/