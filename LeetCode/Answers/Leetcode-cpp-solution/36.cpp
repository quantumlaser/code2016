/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/
class Solution {
public:
    bool state(int x, int i) {return (x>>i) & 0x01;}
    void set(int &x, int i){ x |= (1<<i);}
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9] = {0};
        int col[9] = {0};
        int blk[9] = {0}; 
        for(int i=0; i<9; ++i) 
        for(int j=0; j<9; ++j) {
            if(board[i][j] == '.') continue;
            int c = board[i][j] - '1';
            if(state(row[i], c) || state(col[j], c) || state(blk[(i/3)*3 + j/3], c))
                return false;
            set(row[i], c);
            set(col[j], c);
            set(blk[(i/3)*3 + j/3], c);
        }
        return true;
    }
};