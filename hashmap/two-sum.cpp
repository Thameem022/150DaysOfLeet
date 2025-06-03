#include <vector>
#include <map>

using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // map<int, vector<int>> freq;
    
            // for(int i = 0; i < nums.size(); i++)
            // {
            //     freq[nums[i]].push_back(i);
            // }
    
            // for(int i = 0; i < nums.size(); i++)
            // {
            //     int t = target - nums[i];
            //     if(t == nums[i])
            //     {
            //         if(freq[t].size() > 1)
            //         {
            //             return {freq[t][0], freq[t][1]};
            //         }
            //     }
            //     if(freq.count(t) && t != nums[i])
            //     {
            //         return {i, freq[t][0]};
            //     }
            // }
            // return {-1,-1};
            unordered_map<int, int> seen;  
    
            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
    
                if (seen.count(complement)) {
                    return {seen[complement], i};
                }
    
                seen[nums[i]] = i;
            }
    
            return {-1, -1}; 
        }
    };