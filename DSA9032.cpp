#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int v, e;
vector<int> adj[maxn];
vector<int> visited(maxn);
int size;
int dfs(int i)
{
    visited[i] = 1;
    int size = 1;
    for(int u : adj[i])
    {
        if(!visited[u])
        {
            size += dfs(u);
        }
    }
    return size;
}

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        cin >> v >> e;
        for(int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        for(int i = 1; i <= e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        visited.assign(maxn, 0);
        int res = -1;
        for(int i = 1; i <= v; ++i)
        {
            if(!visited[i])
            {
                res = max(res, dfs(i));
            }
        }
        cout << res << "\n";
    }
    return 0;
}