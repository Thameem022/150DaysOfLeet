#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) 
            return s;
        vector<string> res(numRows);
        int currR = 0;
        bool goingDown = false;
        for(char a : s)
        {
            res[currR]+=a;
            if(currR == 0 || currR == numRows-1)
                goingDown = !goingDown;
            currR+= goingDown? 1: -1;
        }
        string r;
        for(string re:res)
            r+=re;
        return r;
    }
};