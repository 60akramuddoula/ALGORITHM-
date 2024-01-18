#include <bits/stdc++.h>
using namespace std;
void count_negative(int M[3][4], int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (M[i][j] < 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    cout << count << "eito" << endl;
}
int main()
{
    int M[3][4] = {{-3, -2, -1, 1},
                   {-2, 2, 3, 4},
                   {4, 5, 7, 8}};

    count_negative(M, 3, 4);
    return 0;
}