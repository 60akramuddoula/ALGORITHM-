#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << "visiting Node : " << u << " " << endl;

        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            // new jara push hosse tader level paraents
            // theke oviously 1 besi tai level er sathe 1
            // add kora hoyeshe ;
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
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "level of node "
             << i << " " << level[i] << endl;
    }
    return 0;
}