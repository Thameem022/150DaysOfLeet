#include <algorithm>  
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = 0, f = 0;
        int c = 0, farthest = 0;
        while(farthest < (nums.size() - 1))
        {
            int i = 0;
            farthest = 0;
            for(i = n; i <= f; i++)
            {
                farthest = max(farthest ,(nums[i] + i));
            }
            n = n + 1;
            f = farthest;
            c++;
        }
        return c;
    }
};