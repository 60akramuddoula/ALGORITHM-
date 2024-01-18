#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int dist[N];
vector<int> cmp;

void dfs(int s)
{
    visited[s] = true;
    // cout << s << " ";
    cmp.push_back(s);
    for (int i = 0; i < adj[s].size(); i++)
    // use shortcut range based for loop for
    // extracting all the component from the adj vector array
    {
        int v = adj[s][i];
        if (visited[v] == true)
            continue;
        dfs(v);
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
    // dfs(1);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
            for (int val : cmp)
            {
                cout << val << " ";
            }
            cout << endl;
            cmp.clear();
        }
    }
    cout << cnt << endl;
    return 0;
}