class Solution {
public:

    int get_sub_box(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> sub_boxes(9);

        for (int row = 0; row < 9; row++) {
            vector<char> current_row = {};
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                
                char value = board[row][col];

                // Check the row for duplicates
                if (find(current_row.begin(), current_row.end(), board[row][col]) != current_row.end()) {
                    return false;
                }
                // Mark it as seen
                current_row.push_back(value);

                // Check the column
                if (cols[col].contains(value)) {
                    return false;
                } 
                cols[col].insert(value);
                
                // Check the sub grids
                int sub_box = get_sub_box(row, col);

                if (sub_boxes[sub_box].contains(value)) {
                    return false;
                } 
                sub_boxes[sub_box].insert(value);
                
            }
        }
        return true;
    }
};
