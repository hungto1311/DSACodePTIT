#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int v, e;
vector<int> adj[maxn];
vector<int> color(maxn);
bool dfs(int i)
{
    color[i] = 1;
    for (int u : adj[i])
    {
        if (color[u] == 1)
            return true;
        if (color[u] == 0)
        {
            if (dfs(u))
                return true;
        }
    }
    color[i] = 2;
    return false;
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        color.assign(maxn, 0);
        for (int i = 1; i <= e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bool flag = false;
        for (int i = 1; i <= v; ++i)
        {
            if (color[i] == 0)
            {
                if (dfs(i))
                {
                    cout << "YES" << "\n";
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}