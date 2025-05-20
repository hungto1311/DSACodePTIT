#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int v, e, u;
vector<pair<int, int>> adj[maxn];
vector<int> path;

void Dijkstra(int u)
{
    path[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, u});
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        if (p.first > path[p.second])
        {
            continue;
        }
        path[p.second] = p.first;
        for (pair<int, int> n : adj[p.second])
        {
            int vertex = n.first, weight = n.second;
            if (path[vertex] > weight + path[p.second])
            {
                path[vertex] = weight + path[p.second];
                q.push({path[vertex], vertex});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> v >> e >> u;
        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        path.assign(maxn, 1e9);
        for (int i = 1; i <= e; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        Dijkstra(u);
        for (int i = 1; i <= v; ++i)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}