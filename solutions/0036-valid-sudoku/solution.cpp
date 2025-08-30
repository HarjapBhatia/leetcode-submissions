class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][9] = {false};
        bool c[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                const char& ch = board[i][j];
                if (ch == '.') continue;   
                int idx = ch - '1';        
                int bidx = (i / 3) * 3 + (j / 3);
                if (r[i][idx] || c[j][idx] || box[bidx][idx]) return false;
                r[i][idx] = c[j][idx] = box[bidx][idx] = true;
            }
        }
        return true;
    }
};
