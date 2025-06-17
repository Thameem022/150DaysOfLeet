#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> s;
            unordered_map<string, function<int(int, int)>> ops = {
                {"+", [](int a, int b){return a+b; }},
                {"-", [](int a, int b){return a-b; }},
                {"*", [](int a, int b){return a*b; }},
                {"/", [](int a, int b){return a/b; }},
            };
            for(const auto& token:tokens)
            {
                if(ops.count(token))
                {
                    int b = s.top();
                    if(!s.empty()) s.pop();
                    int a = s.top();
                    if(!s.empty()) s.pop();
                    s.push(ops[token](a,b));
                }
                else
                {
                    s.push(stoi(token));
                }
            }
            return s.top();
        }
    };