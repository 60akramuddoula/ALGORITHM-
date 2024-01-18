#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

// void dfs_print(int u)
// {
//     visited[u] = true;
//     cout << u << " ";
//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         dfs_print(v);
//     }
// }

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> components; // double vector bhai
    // component koto index a ache sekhane seta and oi
    // index er vitor ki ki component ache setar jonno use kora
    // houyese
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        vector<int> component;
        dfs(i);
        for (int j = 1; j <= n; j++)
        {
            if (visited[j])
            {
                component.push_back(j);
            }
        }
        components.push_back(component);
        cnt++;
    }

    cout << "Connected components: " << cnt << endl;

    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << " : ";
        for (int node : components[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
