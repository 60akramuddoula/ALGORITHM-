#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
        }
    }
}

void dfs(int u)
{
    visited[u] = true;
    cout << "visiting Node " << u << endl;

    for (int v : adj[u])
    {
        if (visited[v] == true)
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

        // Increment the count before starting a new connected component
        cnt++;

        dfs(i);
    }

    cout << "Number of connected components is " << cnt << " ";
    return 0;
}
