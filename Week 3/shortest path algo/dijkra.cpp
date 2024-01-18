#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<pii> adj[N];
const int INF = 1e9 + 7;
vector<int> dist(N, INF);
bool visited[N];

void diska(int s)
{

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (auto vp : adj[u])
        {
            int v = vp.first;
            int w = vp.second;

            if (visited[v])
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    diska(1);
    for (int i = 1; i <= n; i++)
    {
        cout << " distance of Node " << i
             << dist[i] << " " << endl;
    }
    return 0;
}