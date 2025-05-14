#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> adj(v + 1);
        for (int i = 0; i < e; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        vector<int> deg_plus(v + 5, 0);
        vector<int> deg_minus(v + 5, 0);
        for (int i = 1; i <= v; ++i)
        {
            deg_plus[i] = adj[i].size();
            for (auto x : adj[i])
            {
                deg_minus[x]++;
            }
        }
        bool check = true;
        for (int i = 1; i <= v; ++i)
        {
            if (deg_plus[i] != deg_minus[i])
            {
                cout << 0 << "\n";
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}
