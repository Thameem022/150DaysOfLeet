#include<map>
using namespace std;
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            map<int, int> index;
    
            for(int i = 0; i < nums.size(); i++)
            {
                if(!index.count(nums[i]))
                {
                    index[nums[i]] = i;
                }
                else
                {
                    int v = abs(i - index[nums[i]]);
                    if( v <= k) return true;
                    index[nums[i]] = i;
                }
            }
            return false;
        }
    };