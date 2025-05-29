#include <vector>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size(), n = matrix[0].size();
            // vector<map<int, int>> row(m), col(n);
            // for(int i = 0; i<m; i++)
            // {
            //     for(int j = 0; j<n; j++)
            //     {
            //         row[i][matrix[i][j]]++;
            //         col[j][matrix[i][j]]++;
            //     }
            // }
            // for(int i = 0; i<m; i++)
            // {
            //     for(int j = 0; j<n; j++)
            //     {
            //         if(row[i][0] > 0)
            //         {
            //             matrix[i][j] = 0;
            //         }
            //         if(col[j][0] > 0)
            //         {
            //             matrix[i][j] = 0;
            //         }
            //     }
            // }
            bool firstRow = false, firstCol= false;
            for(int i = 0; i < n; i++)
            {
                if(matrix[0][i] == 0)
                {
                    firstRow = true;
                }
            }
            for(int i = 0; i < m; i++)
            {
                if(matrix[i][0] == 0)
                {
                    firstCol = true;
                }
            }
            for(int i = 1; i < m; i++)
                for(int j = 1; j < n; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            for(int i = 1; i < m; i++)
                for(int j = 1; j < n; j++)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0 ;
                    }
                }
    
            if(firstRow == true)
            {
                for(int i = 0; i < n; i++)
                {
                    matrix[0][i] = 0;
                }
            }
            if(firstCol == true)
            {
                for(int i = 0; i < m; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
    };