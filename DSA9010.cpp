#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int v, e;
vector<int> adj[maxn];
vector<int> adj_rev[maxn];
vector<int> visited;
vector<int> visited_rev;
void dfs(int i)
{
    visited[i] = 1;
    for (int u : adj[i])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
}
void dfs2(int i)
{
    visited_rev[i] = 1;
    for (int u : adj_rev[i])
    {
        if (!visited_rev[u])
        {
            dfs2(u);
        }
    }
}

bool isStronglyConnected()
{
    dfs(1);
    for (int i = 1; i <= v; ++i)
    {
        if (!visited[i])
            return false;
    }
    dfs2(1);
    for (int i = 1; i <= v; ++i)
    {
        if (!visited_rev[i])
            return false;
    }
    return true;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> v >> e;
        visited.assign(maxn, 0);
        visited_rev.assign(maxn, 0);
        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        for (int i = 1; i <= v; ++i)
        {
            adj_rev[i].clear();
        }
        for (int i = 1; i <= e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj_rev[v].push_back(u);
        }
        if (isStronglyConnected())
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}