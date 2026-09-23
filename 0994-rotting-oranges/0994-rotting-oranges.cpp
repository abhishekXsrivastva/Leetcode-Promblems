class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int totalTime = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            totalTime = max(totalTime, time);
            for(int i = 0; i < 4; i++){
                int neighRow = row + dr[i];
                int neighCol = col + dc[i];
                if(neighRow >= 0 && neighRow < n &&
                   neighCol >= 0 && neighCol < m &&
                   vis[neighRow][neighCol] != 2 && grid[neighRow][neighCol] == 1){
                    vis[neighRow][neighCol] = 2;
                    q.push({{neighRow, neighCol}, time + 1});
                   }
            }

        }
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
       }

        return totalTime;
    }
};