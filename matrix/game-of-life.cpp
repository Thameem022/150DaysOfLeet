#include <vector>

using namespace std;

class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size(), n = board[0].size();
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                {
    
                    int score = getNeighboursCount(board, i, j);
                    if( (score < 2 || score > 3)  && board[i][j] == 1)
                    {
                        board[i][j] = 2;
                    }
                    else if (board[i][j] == 0 && score == 3)
                    {
                        board[i][j] = 3;
                    }
                }
            
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                {
                    board[i][j] %=2; 
                }
            
        }
        int getNeighboursCount(vector<vector<int>>& board, int r, int c)
        {
            int m = board.size(), n = board[0].size();
            vector<int> units = {-1, 0, 1};
            int tot = 0;
            for(int i : units)
                for(int j : units)
                {
                    if(i == 0 && j == 0) continue;
                    if ( i + r <= m - 1 && i + r >=0 && c + j >= 0 && c + j <= n-1)
                    {
                        tot += (board[i+r][j+c] == 1 || board[i+r][j+c] == 2)? 1 : 0;
                    }
                }
            return tot;
        }
    };