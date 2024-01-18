#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool visited[N];

void dfs(int u, int &cnt)
{
    visited[u] = true;
    cnt = cnt + 1;

    for (auto v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v, cnt);
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
        adj[v].push_back(u);
    }

    vector<int> v;

       for (int i = 0; i <= 1000; i++)
    {
        if (visited[i] == 0)
        {
            int cnt = 0;
            dfs(i, cnt);
            if (cnt > 1)
            {
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    for (int ans : v)
    {
        cout << ans << " ";
    }
    return 0;
}