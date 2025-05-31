#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            unordered_map<char, int> row[9], column[9], box[9];
            for(int i = 0; i < 9; i++)
                for(int j = 0; j < 9; j++)
                {
                    char c = board[i][j];
                    if( c == '.') continue;
                    int k = (i/3)*3 + j/3;
                    if(row[i].count(c)) 
                    return false;
                    else 
                    row[i][c]++;
                    if(column[j].count(c)) 
                    return false;
                    else 
                    column[j][c]++;
                    if(box[k].count(c)) 
                    return false;
                    else 
                    box[k][c]++;
                }
            return true;
        }
    };