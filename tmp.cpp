
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

int checkSoCP(int n)
{
    int i = 0;
    while (i * i <= n)
    {
        if (i * i == n)
        {
            return 1;
        }
        ++i;
    }
    return 0;
}

int vsMuggle(int n)
{
    int res;
    for (int i = 1; i < n; i++)
    {
        if (checkSoCP(i) == 1)
        {
            res = i;
        }
    }
    return res;
}

int lossQMagic(int n)
{
    int Q = 0;
    for (int i = 1; i <= n; i++)
    {
        if (checkPrimeNumber(i) == 1 && n % i == 0)
        {
            Q = i;
        }
    }
    return Q;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int checkPrimeTogether(int a, int b)
{
    if (gcd(a, b) == 1)
    {
        return 1;
    }
    return 0;
}

void Swapp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int lossQTSLG(int *array, int size)
{
    int arr[200];
    for (int i = 1; i <size; i++)
    {
        arr[i]=array[i];
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                Swapp(arr[i], arr[j]);
            }
        }
    }
    return 0;
}

int main()
{
    int array[1000] = {108, 777, 0, 234, 345, 107, 106};
    int size = 7;
    cout << lossQTSLG(array, size);
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}