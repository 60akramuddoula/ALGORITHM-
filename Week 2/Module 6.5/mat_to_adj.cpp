#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int mat[N][N];
vector<int> adj[N];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List ->" << i << " :";
        for (auto v : adj[i])
        {
            cout << " " << v;
        }
        cout << endl;
    }

    return 0;
}