#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
bool visited[N];
int dist[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentcost = parent.first;
        if (visited[parentNode])
            continue;
        visited[parentNode] = true;
        for (int i = 0; i < adj[parentNode].size(); i++)
        {
            pair<int, int> child = adj[parentNode][i];
            int childnode = child.first;
            int childcost = child.second;
            if (parentcost + childcost < dist[childnode])
            {
                dist[childnode] = parentcost + childcost;
                pq.push({dist[childnode], childnode});
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
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << " : " << dist[i] << endl;
    }
    return 0;
}