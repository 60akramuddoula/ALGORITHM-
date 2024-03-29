#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];

void dfs(int u)
{
    visited[u] = true;
    // cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
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

    dfs(1);

    int x;
    cin >> x;

    cout << "Depth of the node "
         << x << " is " << depth[x] << endl;

    return 0;
}
