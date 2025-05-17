#include <vector>

using namespace std;
class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            int n = words.size();
            int i = 0;
            vector<string> res;
            while ( i<n )
            {
                int lineLen = words[i].size();
                int j = i+1;
    
                while(j < n && (lineLen + words[j].size() + (j - i)) <= maxWidth)
                {
                    lineLen+=words[j].size();
                    j++;
                }
    
                int wordCount = j - i;
                int totalSpace = maxWidth - lineLen;
                string line;
                if( j == n || wordCount == 1)
                {
                    for(int k = i; k < j; ++k)
                    {
                        line+=words[k];
                        if(k != j - 1) line+=' ';
                    }
                    line += string(maxWidth - line.length(), ' ');
                }
                else
                {
                    int wSpace = totalSpace/(wordCount-1);
                    int eSpace = totalSpace%(wordCount-1);
                    for(int k = i; k < j; ++k)
                    {
                        line+=words[k];
                        if (k != j - 1) 
                        {
                        int spaceCount = wSpace + (eSpace-- > 0 ? 1 : 0);
                        line += string(spaceCount, ' ');
                        }
                    }
                }
                res.push_back(line);
                i = j; 
            }
            return res;
        }
    };