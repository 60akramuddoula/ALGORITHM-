#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int dist[N];
int parent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : adj[p])
        {
            if (!visited[child])
            {
                q.push(child);
                parent[child] = p;
                visited[child] = true;
                dist[child] = dist[p] + 1;
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int destination;
    cin >> destination;

    bfs(1);

    if (visited[destination])
    {
        vector<int> path;
        int current = destination;

        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        for (int node : path)
        {
            cout << node << " ";
        }
    }
    else
    {
        cout << "Sorry, no path exists to node " << destination << endl;
    }

    return 0;
}
