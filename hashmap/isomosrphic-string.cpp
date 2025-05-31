#include <map>
#include <set>


using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.size() != t.size()) return false;
            map<char,char> charMap;
            set<char> used;
            for(int i = 0; i < s.size(); i++)
            {
                char sc = s[i], tc = t[i];
                if(charMap.count(sc))
                {
                    if(charMap[sc] != tc) return false;
                }
                else
                {
                    if(used.count(tc)) return false;
                    charMap[sc] = tc;
                    used.insert(tc);
                }
            }
            return true;
        }
    };