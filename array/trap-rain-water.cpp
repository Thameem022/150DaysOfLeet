#include <algorithm>  
#include <vector>

using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int maxL = height[0], maxR = height[n-1];
            int l = 0, r = n - 1, totW = 0;
            
            while (l < r) {
                if (maxL < maxR) {
                    l++;
                    maxL = max(maxL, height[l]);
                    if (min(maxL, maxR) - height[l] > 0) {
                        totW += min(maxL, maxR) - height[l];
                    }
                } else {
                    r--;
                    maxR = max(maxR, height[r]);
                    if (min(maxL, maxR) - height[r] > 0) {
                        totW += min(maxL, maxR) - height[r];
                    }
                }
            }
            return totW;
        }
    };
    