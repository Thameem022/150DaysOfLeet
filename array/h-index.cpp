#include <vector>
using namespace std;
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end());
            int l = citations.size();
            int temp = citations[0];
            for(int i = 1; i<l; i++)
            {
                if(i == l-1 && temp == 0 && citations[i] > 0)
                {
                    return 1;
                }
                int hl = l - i;
                if(citations[i] <= hl)
                {
                    temp = max(temp, citations[i]);
                }
                else
                {
                    temp = max(temp, hl);
                }
            }
            if(temp > l)
            {
                temp = min(temp, l);
            }
            return temp;
        }
    };