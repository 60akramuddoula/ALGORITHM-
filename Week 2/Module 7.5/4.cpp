#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    // cout << u << " ";
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
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
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        cnt++;
        dfs(i);
    }

    cout << "conneted component"
         << " is " << cnt << endl;
    return 0;
}