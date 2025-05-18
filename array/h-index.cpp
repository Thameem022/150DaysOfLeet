#include <vector>
using namespace std;
class Solution {
    public:
    int hIndex(vector<int>& citations) {
        // sort(citations.begin(), citations.end());
        // int l = citations.size();
        // int temp = citations[0];
        // for(int i = 1; i<l; i++)
        // {
        //     if(i == l-1 && temp == 0 && citations[i] > 0)
        //     {
        //         return 1;
        //     }
        //     int hl = l - i;
        //     if(citations[i] <= hl)
        //     {
        //         temp = max(temp, citations[i]);
        //     }
        //     else
        //     {
        //         temp = max(temp, hl);
        //     }
        // }
        // if(temp > l)
        // {
        //     temp = min(temp, l);
        // }
        // return temp;
        vector<int> count(citations.size()+1);
        for(int a: citations)
        {
            if(a < citations.size())
            {
                count[a]++;
            }
            else
            {
                count[citations.size()]++;
            }
        }
        int papCount = 0;
        for(int i = count.size() - 1; i > 0; i--)
        {
            papCount+=count[i];
            if(papCount >= i)
            {
                return i;
            }
        }
        return 0;
    }
};