class Solution {
public:
    void solveNQueensHelper(int i, int n, vector<string>& chess,
                            vector<int>& cols, vector<int>& posDiag,
                            vector<int>& negDiag, vector<vector<string>>& res) {
        if (i >= n) {
            res.push_back(chess);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] == 1 || posDiag[i + j] == 1 ||
                negDiag[i - j + n - 1] == 1) {
                continue;
            }
            chess[i][j] = 'Q';
            cols[j] = 1;
            posDiag[i + j] = 1;
            negDiag[i - j + n - 1] = 1;

            solveNQueensHelper(i + 1, n, chess, cols, posDiag, negDiag, res);

            chess[i][j] = '.';
            cols[j] = 0;
            posDiag[i + j] = 0;
            negDiag[i - j + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        vector<string> chess(n, row);
        vector<vector<string>> res;
        vector<int> cols(n, 0);
        vector<int> posDiag(2 * n - 1, 0);
        vector<int> negDiag(2 * n - 1, 0);

        solveNQueensHelper(0, n, chess, cols, posDiag, negDiag, res);
        return res;
    }
};