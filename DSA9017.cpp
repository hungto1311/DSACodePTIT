#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
int v;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
    {
        cin >> v;
        for(int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        visited.assign(maxn, 0);
        bool flag = true;
        for(int i = 1; i <= v - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        for(int i = 1; i <= v; ++i)
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