#include <algorithm>  
#include <vector>

using namespace std;
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> answer(nums.size());
            int p = 1;
            int zcount = 0;
            for(int i = 0; i < nums.size(); i++ )
            {
                if(nums[i] != 0)
                {
                    p = p * (int)nums[i];
                }
                else
                {
                    zcount++;
                }
    
            }
            if(zcount > 1)
                return answer;
            for(int i = 0; i < nums.size(); i++ )
            {
                
                if( nums[i] == 0)
                {
                    answer[i] = p;
                }
                else if( nums[i] != 0 and zcount == 1)
                {
                    answer[i] = 0;
                }
                else
                {
                    answer[i] = p/nums[i];
                }
            }
            return answer;
             // vector<int> answer(nums.size());
            // int p = 1;
            // int zcount = 0;
            // for(int i = 0; i < nums.size(); i++ )
            // {
            //     if(nums[i] != 0)
            //     {
            //         p = p * (int)nums[i];
            //     }
            //     else
            //     {
            //         zcount++;
            //     }
    
            // }
            // if(zcount > 1)
            //     return answer;
            // for(int i = 0; i < nums.size(); i++ )
            // {
                
            //     if( nums[i] == 0)
            //     {
            //         answer[i] = p;
            //     }
            //     else if( nums[i] != 0 and zcount == 1)
            //     {
            //         answer[i] = 0;
            //     }
            //     else
            //     {
            //         answer[i] = p/nums[i];
            //     }
            // }
            // return answer;
        }
    };