#include <vector>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int hL = haystack.length(), nL = needle.length();
            if (nL == 0) return 0;
            for(int i = 0; i <= hL; i++)
            {
                int j = 0;
                while ( j < nL)
                {
                    if(needle[j] != haystack[i+j] ) break;
                    j++;
                }
                if(j == nL) return i;
            }
            return -1;
        }
    };