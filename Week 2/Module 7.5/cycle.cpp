#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p)
{
    bool CycleExist = false;

    visited[u] = true;
    // cout << u << " ";
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v] == true)
            return true;
        CycleExist |= dfs(v, u);
    }
    return CycleExist;
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

    bool CycleExist = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        CycleExist |= dfs(1, -1);
    }

    if (CycleExist)
        cout << "cycle detected " << endl;
    else
        cout << "No cycle doesnt exist " << endl;
    return 0;
}