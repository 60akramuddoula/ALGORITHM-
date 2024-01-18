#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N]; // initially zero
int dist[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << " ";
        q.pop();

        for (int i = 0; i < adj[parent].size(); i++)
        {
            int child = adj[parent][i];
            if (!visited[child])
            {
                visited[child] = true;
                dist[child] = dist[parent] + 1;
                q.push(child);
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

    bfs(1);

    return 0;
}
