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
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 0) //nhat duoc TSLG
        {
            Nc++;
        }
        else if (array[i] == 1)
        {
        }
        else if (array[i] >= 100 && array[i] <= 199) //Tu than Thuc Tu
        {
            int h1 = FormulaB(i + 1, r);
            int h2 = FormulaB(array[i], r);
            if (h1 >= h2)
            {
                Mc += array[i];
                Mc = Limit999(Mc);
            }
        }
        else if (array[i] >= 200 && array[i] <= 299)
        {
        }
        else if (array[i] >= 300 && array[i] <= 399)
        {
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
    int r = 0;   //random 0->10
    int n = 5;   //TSLG 1->99
    int id = 3;  //character 1->4
    int m = 201; //Mana 0-999
    int array[MAX_SIZE] = {0, 0};
    int size = 2;
    journey(r, n, id, m, array, size);
    return 0;
}