class Solution {
public:
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