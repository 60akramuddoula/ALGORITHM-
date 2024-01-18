#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool visited[N];

void dfs(int u, int &cnt)
{
    visited[u] = true;
    cnt++;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, cnt);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    int k;
    cin >> k;

    int cnt = 0;
    dfs(k, cnt);
    cout << cnt - 1 << endl;
    return 0;
}
