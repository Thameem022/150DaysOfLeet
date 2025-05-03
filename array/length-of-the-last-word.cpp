
#include <algorithm>  
#include <vector>

using namespace std;
class Solution {
    public:
        int lengthOfLastWord(string s) {
            // istringstream ss(s);
            // vector<string> words;
            // string word;
            // while (ss >> word)
            // {
            //     word = word;
            // } 
            // return word.length();
            int n = s.length();
            int count = 0;
            while(s[n-1] == ' ')
                n--;
            for( int i = n - 1; i>=0; i--)
            {
                if(s[i] != ' ')
                    count++;
                else
                    return count;
            }
            return count;
        }
    };