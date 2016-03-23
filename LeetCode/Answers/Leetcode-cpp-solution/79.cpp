/*
 Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;
        vector<vector<bool> > flag(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) {
            if(search(board, flag, word, i, j))
                return true;
        }
        return false;
    }
    bool search(vector<vector<char> > &board, vector<vector<bool> > &flag, string word, int i, int j) {
        if(word.empty()) return true;
        if(word[0]!=board[i][j] || flag[i][j]) return false;
        if(word.size()==1) return true;
        int m = board.size(), n = board[0].size();
        flag[i][j] = true;
        if(i>0 && search(board, flag, word.substr(1), i-1, j))
            return true;
        if(i<m-1 && search(board, flag, word.substr(1), i+1, j)) 
            return true;            
        if(j>0 && search(board, flag, word.substr(1), i, j-1)) 
            return true;
        if(j<n-1 && search(board, flag, word.substr(1), i, j+1)) 
            return true;            
        flag[i][j] = false;
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) {
            if(search(board, word, i, j))   //depth first search
                return true;
        }
        return false;
    }
    bool search(vector<vector<char> > &board, string word, int i, int j) {
        if(word.empty()) return true;                   
        if(word[0]!=board[i][j]) return false;
        if(word.size()==1) return true;
        int m = board.size(), n = board[0].size();
        char ctmp = board[i][j];                            //save the value in current cell
        board[i][j] = '\0';                                 //set '\0' as visited
        if(i>0 && search(board, word.substr(1), i-1, j))    //up
            return true;
        if(i<m-1 && search(board, word.substr(1), i+1, j))  //down
            return true;                
        if(j>0 && search(board, word.substr(1), i, j-1))    //left
            return true;
        if(j<n-1 && search(board, word.substr(1), i, j+1))  //right
            return true;            
        board[i][j] = ctmp;                                 //revert to the previous state
        return false;
    }
};