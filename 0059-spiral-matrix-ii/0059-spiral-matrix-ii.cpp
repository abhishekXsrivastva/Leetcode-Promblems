class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        int m = n;

        vector<vector<int>> matrix(m, vector<int>(n));
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        int num = 1;

        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++){
                matrix[top][i] = num++;
            }
            top++;

            for(int i = top; i <= bottom; i++){
                matrix[i][right] = num++;
            }
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        return matrix;
    }
};