#include<iostream>
#include<vector>
#include<fstream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1, k = 3*(i/3) + j/3;
                    if(row[i][num] || col[j][num] || box[k][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> pos(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        int numCnt = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    addNum(pos, i, j, num);
                    numCnt++;
                }
            }
        }
        solveSudoku(board, pos, numCnt);
        /* 
        for(int i =0;i<9;i++){
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 9; k++){
                    cout<<pos[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
         */
    }
    
    void addNum(vector<vector<vector<bool>>> &pos, int row, int col, int num){
        for(int i = 0; i < 9; i++){
            if(i != col)
                pos[num][row][i] = false;
            if(i != row)
                pos[num][i][col] = false;
        }
        for(int i = 3*(row/3); i < 3*(row/3 + 1); i++){
            for(int j = 3*(col/3); j < 3*(col/3 + 1); j++){
                if( i!= row && j!=col)
                    pos[num][i][j] = false;
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board, vector<vector<vector<bool>>> &pos, int &numCnt) { 
        for(int i = 0; i < 9; i++){
            
        }
    }
};

int main(){
//#define leet37
#ifndef leet37
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif
    vector<vector<char>> board;
    Solution solution;
    solution.solveSudoku(board);
    return 0;
}