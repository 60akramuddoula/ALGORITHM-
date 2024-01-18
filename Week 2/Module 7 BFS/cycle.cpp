#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p) // p bcz check  krbo jar kase jai se parnt kina
{
    bool cycleExist = false;
    visited[u] = true;
    // cout << "visiting Node " << u << endl;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v] == true)
            return true;
        cycleExist = cycleExist | dfs(v, u);
    }
    return cycleExist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle |= dfs(i, -1);
    }

    if (isCycle)
        cout << "detected cycle" << endl;
    else
        cout << " No not detected " << endl;

    return 0;
}
