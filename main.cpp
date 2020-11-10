#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX_SIZE = 200;

int FormulaB(int x, int R) //cong thuc b)
{
    return x % (100 + R);
}

int Limit999(int &x)
{
    if (x > 999)
        return 999;
    return x;
}

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
    for (int i = 1; i < R; i++)
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

void journey(int r, int n, int id, int m, int array[], int size)
{
    int isHarry = 0;
    int isHermione = 0;
    int isRon = 0;
    int isGinny = 0;
    int Nc = 0;
    int Mc = m;
    int HPmax;
    if (id == 1)
    {
        isHarry = 1;
        HPmax = 999;
    }
    else if (id == 2)
    {
        isHermione = 1;
        HPmax = 900;
    }
    else if (id == 3)
    {
        isRon = 1;
        HPmax = 888;
    }
    else if (id == 4)
    {
        isGinny = 1;
        HPmax = 777;
    }
    int HPc = HPmax;
    int i;
    int Muggle = 0;
    int ammor = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] == 0) //nhat duoc TSLG
        {
            Nc++;
        }
        else if (array[i] == 1) //noi tru an HPPPPP
        {
            if (HPc < HPmax) //neu het mau
            {
                if (id == 3) //Ron
                {
                    if (r >= 3)
                    {
                        int P = getRonMoney(r);
                        for (int i = 0; i < Mc; i++)
                        {
                            if (Mc < P)
                            {
                                break;
                            }
                            Mc -= P;
                            HPc++;
                        }
                    }
                }
                else if (id != 3)
                {
                    int deal = HPmax - HPc; //so tien can tra
                    if (deal <= Mc)
                    {
                        Mc -= deal;
                        HPc += deal;
                    }
                    else if (deal > Mc)
                    {
                        HPc += Mc;
                        Mc = 0;
                    }
                }
            }
        }
        else if (array[i] >= 100 && array[i] <= 199) //Tu than Thuc Tu
        {
            int h1 = FormulaB(i + 1, r);
            int h2 = FormulaB(array[i], r);
            if (ammor == 1)
            {
                if (id == 1)
                {
                    if (checkPrimeNumber(h2) == 1 && h2 > Mc)
                    {
                        continue;
                    }
                }
                else
                {
                    if (h1 < h2)
                    {
                        continue;
                    }
                }
            }
            else if (ammor == 0)
            {
                if (id == 1)
                {
                    if (checkPrimeNumber(h2) == 1 && h2 > Mc)
                    {
                        HPc -= array[i];
                    }
                    else
                    {
                        Mc += array[i];
                        Mc = Limit999(Mc);
                    }
                }
                else if (id != 1)
                {
                    if (h1 >= h2)
                    {
                        Mc += array[i];
                        Mc = Limit999(Mc);
                    }
                    else if (h1 < h2)
                    {
                        HPc -= array[i];
                    }
                }
            }
        }
        else if (array[i] >= 200 && array[i] <= 299) //Muggle
        {
            if (ammor == 0)
            {
                if (Muggle == 1)
                {
                    Muggle = 0;
                }
                else
                {
                    int tmp = Mc - (array[i] % 200);
                    if (tmp <= 4)
                    {
                        Muggle = 1;
                        i -= 3;
                    }
                    else if (tmp > 4)
                    {
                        Mc = vsMuggle(tmp);
                    }
                }
            }
        }
        else if (array[i] >= 300 && array[i] <= 399) //Nhan su
        {
            int h1 = FormulaB(i + 1, r);
            int h2 = FormulaB(array[i], r);
            if (h1 < h2)
            {
                Nc = 0;
            }
            else if (h1 >= h2)
            {
                ammor = 1;
            }
        }
        else if (array[i] >= 400 && array[i] <= 499)
        {
        }
        else if (array[i] >= 500 && array[i] <= 599)
        {
        }
        else if (array[i] == 666)
        {
        }
        else if (array[i] == 777)
        {
        }
        else if (array[i] == 999)
        {
        }
        if (Nc == n) //full TSLG
        {
            cout << HPc + Mc;
            return;
        }
        if (HPc <= 0) //Loser
        {
            cout << -1;
            return;
        }
    }
    cout << 0; //Failed Game
}
int main()
{
    int r = 0;  //random 0->10
    int n = 2;  //TSLG 1->99
    int id = 2; //character 1->4
    int m = 11; //Mana 0-999
    int array[MAX_SIZE] = {0, 309, 0, 0};
    int size = 4;
    journey(r, n, id, m, array, size);
    return 0;
}