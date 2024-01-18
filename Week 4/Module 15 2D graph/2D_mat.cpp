#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1005;
bool visited[N][N];
int dist[N][N];
int n, m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isvalid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    visited[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        // move to charedike so children 4 ta only
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
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

int main()
{

    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}