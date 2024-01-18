#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> v[N];

void dfs(int s)
{
    cout << s << " ";
    visited[s] = true;
    for (int i = 0; i < v[s].size(); i++)
    // for(int child: v[s])
    {
        int child = v[s][i];
        if (visited[child])
            continue;
        dfs(child);
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    return 0;
}