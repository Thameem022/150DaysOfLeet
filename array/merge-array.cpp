#include <vector>

using namespace std;
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // nums1.erase(nums1.begin() + m, nums1.end());
        // nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
        // sort(nums1.begin(), nums1.end());
        // nums1.resize(m+n);    
    
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
    
        while ( i >= 0 && j >= 0 )
        {
            if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }    
    
        while ( j >= 0 )
        {
            nums1[k--] = nums2[j--];
        }
        }
    };