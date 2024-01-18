#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
vector<pii> adj[N];
int dist[N];
bool visited[N];

void diska(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        pii p = pq.top(); // ekhane pair soho ache parent node er
        pq.pop();
        int pCost = p.first;
        int pNode = p.second;
        if (visited[pNode])
        {
            continue;
        }
        visited[pNode] = true;

        for (int i = 0; i < adj[pNode].size(); i++)
        {
            pii c = adj[pNode][i];
            int cNode = c.first;
            int cCost = c.second;
            if (pCost + cCost < dist[cNode])
            {
                dist[cNode] = pCost + cCost;
                pq.push({dist[cNode], cNode});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    diska(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "node distance " << i << " :" << dist[i] << endl;
    }
    return 0;
}