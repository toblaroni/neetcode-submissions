class Solution {
public:

    int get_sub_box(int row, int col) {
        int r_sub = floor(row / 3);
        int c_sub = floor(col / 3);

        if (r_sub == 0 && c_sub == 0) {
            return 0;
        } else if (r_sub == 0 && c_sub == 1) {
            return 1;
        } else if (r_sub == 0 && c_sub == 2) {
            return 2;
        } else if (r_sub == 1 && c_sub == 0) {
            return 3;
        } else if (r_sub == 1 && c_sub == 1) {
            return 4;
        } else if (r_sub == 1 && c_sub == 2) {
            return 5;
        } else if (r_sub == 2 && c_sub == 0) {
            return 6;
        } else if (r_sub == 2 && c_sub == 1) {
            return 7;
        } else {
            return 8;
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<char>> cols;
        unordered_map<int, vector<char>> sub_boxes;

        for (int row = 0; row < 9; row++) {
            vector<char> current_row = {};
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;

                // Check the row for duplicates
                bool char_exists = find(
                    current_row.begin(), 
                    current_row.end(), 
                    board[row][col]
                ) != current_row.end();

                if (!char_exists) {
                    // Char hasn't been seen yet
                    current_row.push_back(board[row][col]);
                }
                else {
                    return false;
                }

                // Check the column
                char_exists = find(
                    cols[col].begin(),
                    cols[col].end(),
                    board[row][col]
                ) != cols[col].end();
                if (!char_exists) {
                    cols[col].push_back(board[row][col]);
                } else {
                    return false;
                }
                
                // Check the sub grids
                int sub_box = get_sub_box(row, col);
                
                char_exists = find(
                    sub_boxes[sub_box].begin(),
                    sub_boxes[sub_box].end(),
                    board[row][col]
                ) != sub_boxes[sub_box].end();
                if (!char_exists) {
                    sub_boxes[sub_box].push_back(board[row][col]);
                } else {
                    return false;
                }
                
            }
        }
        return true;
    }
};
