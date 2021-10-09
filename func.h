#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 100
using namespace std;

class Solution
{
private:
    int St;                    //state
    int In;                    //input
    int raw1[SIZE][SIZE];      //NS
    int raw2[SIZE][SIZE];      //Out
    int trans[SIZE][SIZE];     //state judge
    int check[SIZE * SIZE][2]; //solve dead recursion

public:
    void in1(int a, int b, int ii[][SIZE])
    {
        St = a;
        In = b;
        for (int i = 0; i < SIZE; i++)
        {
            check[i][0] = -1;
            check[i][1] = -1;
        }
        for (int i = 0; i < St - 1; i++)
        {
            for (int j = i + 1; j < St; j++)
            {
                trans[i][j] = -1;
            }
        }
        for (int i = 0; i < St; i++)
        {
            for (int j = 0; j < In; j++)
            {
                raw1[i][j] = ii[i][j] - 1;
            }
        }
    }

    void in2(int ii[][SIZE])
    {
        for (int i = 0; i < St; i++)
        {
            for (int j = 0; j < In; j++)
            {
                raw2[i][j] = ii[i][j];
            }
        }
    }

    void calc()
    {
        for (int i = 0; i < St - 1; i++)
        {
            for (int j = i + 1; j < St; j++)
            {
                for (int k = 0; k < In; k++)
                {
                    if (raw2[i][k] != raw2[j][k])
                    {
                        trans[i][j] = 0;
                        break;
                    }
                }
            }
        }

        int t;
        for (int i = 0; i < St - 1; i++)
        {
            for (int j = i + 1; j < St; j++)
            {
                t = 0;
                while (check[t][0] != -1)
                {
                    check[t][0] = -1;
                    check[t][1] = -1;
                    t++;
                }
                if (trans[i][j] == -1)
                {
                    trans[i][j] = simplify(i, j);
                }
            }
        }
    }

    void out(int oo[][SIZE])
    {
        for (int i = 0; i < St; i++)
        {
            for (int j = 0; j < St; j++)
            {
                oo[i][j] = trans[i][j];
            }
        }
    }

    int m(int a, int b)
    {
        if (a <= b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int M(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int simplify(int a, int b) //a<=b
    {
        if (a == b)
        {
            return 1;
        }
        if (trans[a][b] == 1 || trans[a][b] == 0)
        {
            return trans[a][b];
        }
        int temp = 0;
        while (check[temp][0] != -1)
        {
            if (a == check[temp][0] && b == check[temp][1])
            {
                return 1;
            }
            temp++;
        }
        check[temp][0] = a;
        check[temp][1] = b;

        int final = 1;
        for (int i = 0; i < In; i++)
        {
            if (simplify(m(raw1[a][i], raw1[b][i]), M(raw1[a][i], raw1[b][i])) == 0)
            {
                final = 0;
                break;
            }
        }
        trans[a][b] = final;
        return final;
    }
};

#endif // !1
