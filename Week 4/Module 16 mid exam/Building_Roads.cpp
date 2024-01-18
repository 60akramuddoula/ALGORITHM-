#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];

void dfs(int s)
{
    visited[s] = true;
    // cout << s << " ";
    for (int child : adj[s])
    {
        if (visited[child] == true)
        {
            continue;
        }
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // dfs(1);

    vector<int> ans;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        dfs(i);
        ans.push_back(i);
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}