class Solution {
public:
    void bfs(int startRow, int startCol, vector<vector<int>>& res, vector<vector<int>>& image, int& iniColor, int& color){
        int n = image.size();
        int m = image[0].size();
        res[startRow][startCol] = color;
        queue<pair<int,int>>q;
        q.push({startRow, startCol});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int newRow = q.front().first;
            int newCol = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = newRow + delRow[i];
                int nCol = newCol + delCol[i];
                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   image[nRow][nCol] == iniColor && res[nRow][nCol] != color){
                    res[nRow][nCol] = color;
                   q.push({nRow, nCol});
                   }
            }

        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res = image;
        int iniColor = image[sr][sc];
        if(color == iniColor) return image;
        bfs(sr, sc, res, image, iniColor, color);
        return res;
    }
};
/*
---> using dfs ---->
void dfs(int row, int col, vector<vector<int>>& res, vector<vector<int>>& image, int& iniColor, int& color){
        res[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == iniColor &&
               res[nrow][ncol] != color){
                dfs(nrow, ncol, res, image, iniColor, color);
               }
        }
    }
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> res = image;
        dfs(sr, sc, res, image, iniColor, color);
        return res;
    }
};
*/