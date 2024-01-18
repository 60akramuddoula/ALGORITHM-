#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> vec;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        vec.push_back(ed);
        // cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }

    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) // jot bar relax korbo
    {
        for (int j = 0; j < vec.size(); j++)
        {
            Edge ed = vec[j];
            if (dist[ed.u] + ed.w < dist[ed.v])
            {
                dist[ed.v] = dist[ed.u] + ed.w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << " :" << dist[i] << endl;
    }
    return 0;
}

// but it still  cant not detect negtive cycle
// as far this . Dijkstra can also perform but when negative
// cycle arrizes it can not perform  and here bellman ford arrises