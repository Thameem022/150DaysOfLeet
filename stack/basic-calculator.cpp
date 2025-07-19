
#include <iostream>
#include <stack>
using namespace std;
int main()
{

    string test = "(3 + 1) - (2 + 1 - (7 + 8))";
    
    stack<int> stk;
    int res = 0, sign = 1, num = 0;
    
    for(char a:test)
    {
        if(isdigit(a))
        {
            num = num*10+ (a - '0');
        }
        else if(a == '+' || a == '-')
        {
            res += sign * num;
            num = 0;
            sign = (a == '+')? 1:-1;
        }
        else if(a == '(')
        {
            stk.push(res);
            stk.push(sign);
            sign = 1;
            res = 0;
        }
        else if(a == ')')
        {
            res += sign*num;
            num=0;
            res *= stk.top();
            stk.pop();
            res+=stk.top();
            stk.pop();
        }else if(a==' ') continue;
    }
    res+=sign*num;
    cout<<res;
}