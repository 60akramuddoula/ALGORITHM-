#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dist[N];

void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < adj[parent].size(); i++)
        {
            pair<int, int> child = adj[parent][i];
            int childnode = child.first;
            int childcost = child.second;

            // check relaxation rather than visited
            if (dist[parent] + childcost < dist[childnode])
            {
                dist[childnode] = dist[parent] + childcost;
                // relax kora gelo so print kori ekhon
                q.push(childnode);
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
        // initially all node er distance infinity rekhe dilam
    }

    dijkstra(3);

    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << ": " << dist[i] << endl;
    }

    return 0;
}
