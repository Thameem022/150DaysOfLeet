#include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int size = nums.size() - 1;
            for(int i = size; i>=0; i--)
            {
                if((i + nums[i]) >= size)
                {
                    size = i;
                }
            }
            if(size == 0)
                return true;
            return false;
        }
    
    };