#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int row = matrix.size(), col = matrix[0].size();
            int top = 0, right = col -1 , bottom = row - 1, left = 0;
            if(row == 0) return {};
            vector<int> res;
            res.reserve(row*col);
            while( bottom >= top && left <= right )
            {
                for(int i = left; i <= right; i++ ) res.push_back(matrix[top][i]);
                top++;
                for(int i = top; i <= bottom ; i++ ) res.push_back(matrix[i][right]);
                right--;
                if(bottom >= top)
                {
                    for(int i = right; i >= left; i-- ) res.push_back(matrix[bottom][i]);
                    bottom--;
                }
                if(left <= right)
                {
                    for(int i = bottom; i >= top; i-- ) res.push_back(matrix[i][left]);
                    left++;
                }
            }
            return res;
        }
    };