#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int INF = 1e9 + 9;
int dist[N][N];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    // floyd warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }
}