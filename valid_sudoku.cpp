class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet, colSet;
            for (int j = 0; j < 9; ++j) {
                // Check for duplicates in rows
                if (board[i][j] != '.' && !rowSet.insert(board[i][j]).second) {
                    return false;
                }
                // Check for duplicates in columns
                if (board[j][i] != '.' && !colSet.insert(board[j][i]).second) {
                    return false;
                }
            }
        }

        // Check 3x3 subgrids
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> subgridSet;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char num = board[row + i][col + j];
                        if (num != '.' && !subgridSet.insert(num).second) {
                            return false;
                        }
                    }
                }
            }
        }

        return true; // If no duplicates are found
    }
};
