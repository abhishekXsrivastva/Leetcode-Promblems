class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == 0 && 1 + dis < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == n-1 && ncol == n-1)
                        return dis + 1;
                        q.push({dis+1, {nrow, ncol}});
                    
               }
            }
        }
          return -1;  
    }
};