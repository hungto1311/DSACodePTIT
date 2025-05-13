#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int v, e;
vector<int> adj[maxn];
vector<int> visited(maxn);
vector<int> parents(maxn);

bool dfs(int i)
{
    visited[i] = 1;
    for(int u : adj[i])
    {
        if(visited[u] && u != parents[i])
        {
            return true;
        }
        if(!visited[u])
        {
            parents[u] = i;
            if(dfs(u)) return true;
        }
    }
    return false;
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
        visited.assign(maxn, 0);
        parents.assign(maxn, -1);
        for(int i = 1; i <= e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = false;
        for(int i = 1; i <= v; ++i)
        {
            if(!visited[i])
            {
                if(dfs(i))
                {
                    cout << "YES" << "\n";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}