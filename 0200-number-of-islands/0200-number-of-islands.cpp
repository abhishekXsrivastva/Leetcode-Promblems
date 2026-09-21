class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0,-1};

        while(!q.empty()){
        int newRow = q.front().first;
        int newCol = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int neighRow = newRow + dr[k];
            int neighCol = newCol + dc[k];

            if(neighRow >= 0 && neighRow < n &&
               neighCol >= 0 && neighCol < m &&
               !vis[neighRow][neighCol] && grid[neighRow][neighCol] == '1'){
                vis[neighRow][neighCol] = 1;
                q.push({neighRow, neighCol});
               }
        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j= 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};