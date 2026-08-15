class Solution {
public:
    bool isVaild(int newRow, int newCol, int n){
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];

        priority_queue<pair<int, pair<int, int>>,
                      vector<pair<int, pair<int, int>>>,
                      greater<pair<int, pair<int, int>>>> pq;
          pq.push({dist[0][0], {0, 0}});

          int dr[] = {-1, 0, 1, 0};
          int dc[] = {0, 1, 0, -1};

          while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1){
                return time;
            }
            for(int i = 0; i < 4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(isVaild(newRow, newCol, n)){
                 int newTime = max(time, grid[newRow][newCol]);
                 if(newTime < dist[newRow][newCol]){
                    dist[newRow][newCol] = newTime;
                    pq.push({newTime, {newRow, newCol}});
                 }
                }
            }
          } 
          return -1;           
    }
};