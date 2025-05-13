#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
vector<int> adj[maxn];
vector<int> visited;
void dfs(int i)
{
    visited[i] = 1;
    for(int u : adj[i])
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            adj[i].clear();
        }
        visited.assign(maxn, 0);
        bool flag = true;
        int maxNode = -1e9;
        for(int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            maxNode = max({maxNode, u, v});
        }
        if(n - 1 != maxNode - 1)
        {
            cout << "NO" << "\n";
            break;
        }
        dfs(1);
        for(int i = 1; i <= n; ++i)
        {
            if(!visited[i])
            {
                cout << "NO" << "\n";
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "YES" << "\n";
        }
    }

    return 0;
}