#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
int v, e, timer;
vector<int> adj[maxn];
vector<int> visited, low, tin, ap;
void dfs(int v, int p = -1)
{
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    int child = 0;
    for(int to : adj[v])
    {
        if(to == p) continue;
        if(visited[to])
        {
            low[v] = min(tin[to], low[v]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[to], low[v]);
            if(low[to] >= tin[v] && p != -1)
            {
                ap[v] = 1;
            }
            ++child;
        }
    }
    if(p == -1 && child >= 2)
    {
        ap[v] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
    {
        cin >> v >> e;
        for(int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        timer = 0;
        visited.assign(maxn, 0);
        low.assign(maxn, -1);
        tin.assign(maxn, -1);
        ap.assign(maxn, 0);
        for(int i = 1; i <= e; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= v; ++i)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        for(int i = 1; i <= v; ++i)
        {
            if(ap[i])
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
