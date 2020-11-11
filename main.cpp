#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1000;

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
                    else
                    {
                        Mc += array[i];
                        Mc = Limit999(Mc);
                    }
                }
                else
                {
                    if (h1 < h2)
                    {
                        continue;
                    }
                    else if (h1 >= h2)
                    {
                        Mc += array[i];
                        Mc = Limit999(Mc);
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
                        if (i + 1 < 3)
                        {
                            cout << 0;
                            return;
                        }
                        else
                        {
                            i -= 3;
                        }
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
                Nc = 0; //mat TSLG
            }
            else if (h1 >= h2)
            {
                ammor = 1;
            }
        }
        else if (array[i] >= 500 && array[i] <= 599) //Nguoi khong lo
        {
            int h1 = FormulaB(i + 1, r);
            int h2 = FormulaB(array[i], r);
            if (id == 2 || id == 4) //Ginny va Her
            {
                if (checkPrimeTogether(array[i] % 500, HPc))
                {
                    continue;
                }
            }
            if (h1 < h2)
            {
                HPc -= array[i];
                int Q; //mat Q suc manh
                int tmp = array[i] % 500;
                if (tmp <= 1)
                {
                    Q = 1;
                }
                else if (tmp > 1)
                {
                    Q = lossQMagic(tmp);
                }
                //Tru Q Mana
                if (Q > Mc)
                {
                    Mc = 0;
                }
                else
                {
                    Mc -= Q;
                }
            }
        }
        else if (array[i] == 666) //Bell
        {
            int h1 = FormulaB(i + 1, r);
            int h2 = FormulaB(array[i], r);
            if(h1<h2)
            {
                HPc-=array[i];
                int Q;  //Loss TSLG

            }
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
    int id = 4; //character 1->4
    int m = 11; //Mana 0-999
    int array[MAX_SIZE] = {0, 300, 108, 0};
    int size = 4;
    journey(r, n, id, m, array, size);
    return 0;
}