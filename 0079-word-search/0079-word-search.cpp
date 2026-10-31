class Solution {
public:
    bool existHelper(int row, int col, int idx, string word,
                     vector<vector<char>>& board) {
        if (idx == word.length()) {
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }
        if (board[row][col] != word[idx])
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; dir++) {
            int nrow = row + delRow[dir];
            int ncol = col + delCol[dir];
            if (existHelper(nrow, ncol, idx + 1, word, board)) {
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    existHelper(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};