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