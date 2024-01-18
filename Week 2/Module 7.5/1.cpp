#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}

void bfs(int s)
{
    queue<int> q;
    stack<int> st;
    q.push(s);

    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        st.push(u);
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
        }
    }

    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs(1);
    bfs(1);
    return 0;
}