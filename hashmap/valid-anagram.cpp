#include <vector>
using namespace std;
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false;
            vector<int> freq(256, 0);
            for(char a : s)
            {
                freq[a]++;
            }
            for(char a: t)
            {
                freq[a]--;
                if(freq[a] < 0) return false;
            }
            return true;
        }
    };