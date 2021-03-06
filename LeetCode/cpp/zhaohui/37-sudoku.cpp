#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<string>
using std::vector;
using std::set;
using std::cout;
using std::cin;
using std::endl;
class Solution {
    struct Cell{
        int row;
        int col;
        set<int> possibility;
    };
    vector<Cell> leftCell;
    // TODO 可以用其保存后面还没有填充的地方。
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1, k = 3 * (i / 3) + j / 3;
					if (row[i][num] || col[j][num] || box[k][num])
						return false;
					else
						row[i][num] = col[j][num] = box[k][num] = true;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		set<int> ps;
		for (int i = 0; i < 9; i++) {
			ps.insert(i);
		}
		vector<vector<set<int>>> poss(9, vector<set<int>>(9, set<int>(ps.begin(), ps.end())));
		int numCnt = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1;
					addSudokuNum(poss, i, j, num);
					numCnt++;
				}
			}
		}
		solveSudoku(board, poss, numCnt);
	}

	bool solveSudoku(vector<vector<char>>& board, vector<vector<set<int>>> &poss, int &numCnt) {
		while (numCnt<9 * 9) {
			int numPre = numCnt;
			int minPoss = 10;
			int minLoc[2];
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') {
						int possNum = poss[i][j].size();
						if (possNum < minPoss) {
							minPoss = possNum;
							minLoc[0] = i;
							minLoc[1] = j;
						}
						if (possNum == 1) {
							int num = *(poss[i][j].begin());
							board[i][j] = '0' + num + 1;
							addSudokuNum(poss, i, j, num);
							numCnt++;
						}
					}
				}
			}
			if (numPre == numCnt) {
				if (!minPoss) return false;
				vector<vector<char>> boardBak = board;
				vector<vector<set<int>>> possBak = poss;
				for (int i = 0; i < 9; i++) {
				    if(poss[minLoc[0]][minLoc[1]].find(i) == poss[minLoc[0]][minLoc[1]].end() )
				        continue;
					int numCntBak = numCnt;
					addSudokuNum(poss, minLoc[0], minLoc[1], i);
					board[minLoc[0]][minLoc[1]] = '0' + i + 1;	
					numCnt++;

					if (solveSudoku(board, poss, numCnt))
						return true;
					else {
						//recoverSudoku(board, poss, boardBak, possBak);
						board = boardBak;
						poss = possBak;
						numCnt = numCntBak;
						//board[minLoc[0]][minLoc[1]] = '.';
					}						
				}			
				return false;
			}
		}
		return true;
	}
    
    void addSudokuNum(vector<vector<set<int>>> & poss, int row, int col, int num) {
		for (int i = 0; i < 9; i++) {
			if (i != col)
				poss[row][i].erase(num);
			if (i != row)
				poss[i][col].erase(num);
		}
		for (int i = 3 * (row / 3); i < 3 * (row / 3 + 1); i++) {
			for (int j = 3 * (col / 3); j < 3 * (col / 3 + 1); j++) {
				if (i != row && j != col)
					poss[i][j].erase(num);
			}
		}
	}
    
	void recoverSudoku(vector<vector<char>> &board, vector<vector<set<int>>> &poss,
		vector<vector<char>> &boardBak, vector<vector<set<int>>> &possBak) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				board[i][j] = boardBak[i][j];
				for (set<int>::iterator it = possBak[i][j].begin(); it != possBak[i][j].end(); it++) {
					poss[i][j].insert(*it);
				}
			}
		}
	}
    
	void printSudoku(vector<vector<char>> &board) {
		//int left = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j]<<" ";
				//if (board[i][j] == '.') left++;

			}
			cout << endl;
		}
        cout<<endl;
		//cout << "left: " << left << endl<<endl;
	}
	
};

int main() {
	//#define leet37
#ifndef leet37
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
#endif
	vector<vector<char>> board(9, vector<char>(9, '.'));
	char c;
	int i = 0, j = 0;
	for (int i = 0; i<9; i++) {
		cin.ignore(2);
		for (int j = 0; j<9; j++) {
			cin >> board[i][j];
		}
		cin.ignore();
	}
	cin.ignore();
    
	Solution solution;
    solution.printSudoku(board);
	solution.solveSudoku(board);
	solution.printSudoku(board);
	cout << "valid: "<<solution.isValidSudoku(board) << endl;
	return 0;
}