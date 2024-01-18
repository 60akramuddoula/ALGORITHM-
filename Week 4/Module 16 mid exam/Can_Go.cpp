#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<pair<int, int>> v[N];
int dis[N];
bool visited[N];

void Dijktra(int s)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    dis[s] = 0;
    pq.push({dis[s], s});

    while (!pq.empty())
    {
        auto parent = pq.top().second;
        auto parentcost = pq.top().first;
        pq.pop();

        if (visited[parent])
            continue;
        visited[parent] = true;

        for (auto &&i : v[parent])
        {
            auto child = i.second;
            auto weight = i.first;
            if (dis[child] >= parentcost + weight)
            {
                dis[child] = parentcost + weight;
                pq.push({dis[child], child});
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({w, b});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    int src;
    cin >> src;
    Dijktra(src);

    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        int a, b;
        cin >> a >> b;
        if (dis[a] <= b)
            cout << "YES" << endl;

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
