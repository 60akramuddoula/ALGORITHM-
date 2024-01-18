#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool visited[N][N];
int dist[N][N];
int n, m;
vector<pair<int, int>> path = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isvalid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();

        // move to child positions
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> p = path[i];
            int ci = p.first + pI;
            int cj = p.second + pJ;

            if (isvalid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dist[ci][cj] = dist[pI][pJ] + 1;
            }
        }
    }
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        bfs(ki, kj);

        if (visited[qi][qj])
        {
            cout << dist[qi][qj] << endl;
        }
        else
        {
            cout << -1 << endl;
        }

        reset();
    }

    return 0;
}
