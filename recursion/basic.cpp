#include<iostream>

using namespace std;

class Sol
{
    public:
        void printDecreasingNumber(int n)
        {
            if(n == 1)
            {
                cout<<n<<endl;
                return;
            }
            cout<<n<<endl;
            printDecreasingNumber(n-1);
        }

        void printIncreasing(int n)
        {
            if(n == 0) return;
            printIncreasing(n-1);
            cout<<n<<endl;
        }

        void printBoth(int n)
        {
            if(n==1) {cout<<1<<endl; return;};
            cout<<n<<endl;
            printBoth(n-1);
            cout<<n<<endl;
        }

        int factorial(int n)
        {
            if(n == 1) return 1;
            return n * factorial(n-1); 
        }

        int power(int x, int n)
        {
            if(n == 0) return 1;

            return x * power(x, n-1);
        }

        double powerLog(double x, double n)
        {
            if(n == 1 || n == 0) return 1;
            if( (int)n%2 == 1)
            {
                return powerLog(x,n/2)*powerLog(x,n/2)*x;
            }
            else
            {
                return powerLog(x,n/2)*powerLog(x,n/2);
            }
        }
};

int main()
{
    Sol sol;
    // sol.printDecreasingNumber(10);   
    int curr = 0;
    cout<<sol.power(5,10)<<endl;  
    return 0;
}