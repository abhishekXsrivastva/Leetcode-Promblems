class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res;
        bool up = true;

        int row = 0, col = 0;

        for(int i = 0; i < n*m; i++){
            res.push_back(mat[row][col]);

            if(up){
                if(col == m - 1){
                    row++;
                    up = false;
                }else if(row == 0){
                    col++;
                    up = false;
                }else{
                    row--;
                    col++;
                }
            }else{
                if(row == n - 1){
                    col++;
                    up = true;
                }else if(col == 0){
                    row++;
                    up = true;
                }else{
                    row++;
                    col--;
                }
            }
        }
        return res;
        // map<int, vector<int>> mpp;
        // vector<int> res;

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         mpp[i+j].push_back(mat[i][j]);
        //     }
        // }
        // bool rev = true;
        // for(auto &it : mpp){
        //     if(rev){
        //         reverse(it.second.begin(), it.second.end());
        //     }
        
        // for(int &num : it.second){
        //     res.push_back(num);
        // }
        // rev = !rev;
        // }
        // return res;
    }
};