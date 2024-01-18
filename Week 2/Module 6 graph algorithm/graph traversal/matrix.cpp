#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int adjMat[N][N];
int main()
{

    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        // 2 ta kore node inpt naw and then
        // tader edge er connection daw
        int u, v, w;
        cin >> u >> v >> w;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // For undirected graph, connect both ways
    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
