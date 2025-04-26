#include <vector>
using namespace std;
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
    
            int totCost = 0,totGas = 0;
            for(int i = 0; i<n; i++)
            {
                totCost+=cost[i];
                totGas+=gas[i];
            }
            if(totCost > totGas)
            {
                return -1;
            }
            int remGas = 0;
            int start = 0;
            for(int i =0; i<n; i++)
            {
                remGas = remGas + gas[i] - cost[i];
                if(remGas < 0)
                {
                    remGas = 0;
                    start = i + 1;
                }
            }
            return start;
    
            // for(int i =0; i<n; i++)
            // {   
            //     int remGas = 0;
            //     if(cost[i] <= gas[i])
            //     {
            //         remGas+=gas[i];
            //         remGas-=cost[i];
            //         int k = (i + 1)%n;
            //         int count = 0;
                    
            //         while(count < n)
            //         {
            //             remGas = remGas + gas[k];
            //             if (remGas >= cost[k])
            //             {
            //                 remGas -=cost[k];
            //                 k = (k+1)%n;
            //                 if(count == n - 1 )
            //                 {
            //                     return i;
            //                 }
            //                 count++;
            //             }
            //             else
            //             {
            //                 break;
            //             }
            //         }
            //     }
            // }
            // return -1;
        }
    };