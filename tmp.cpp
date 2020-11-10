
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX_SIZE = 200;

int checkPrimeNumber(int x)
{
    int S = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            S++;
        }
    }
    if (S == 2)
    {
        return 1;
    }
    return 0;
}

int getRonMoney(int R)
{
    int P;
    for (int i = 0; i < R; i++)
    {
        if (checkPrimeNumber(i) == 1)
            P = i;
    }
    return P;
}

int checkSoCP(int n){
  int i = 0;
  while(i*i <= n){
        if(i*i == n){
            return 1;
        }
        ++i;
    }
    return 0;
}

int vsMuggle(int n)
{
    int res;
    for(int i=1;i<n;i++)
    {
        if(checkSoCP(i)==1)
        {
            res=i;
        }
    }
    return res;
}

int lossQMagic(int n)
{
    
}

int main()
{
    cout << vsMuggle(101-01);
    return 0;
}