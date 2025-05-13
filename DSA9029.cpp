#include <iostream>
#include <vector>
using namespace std;
#define maxn 15
int v, e;
vector<int> adj[maxn];
vector<int> visited(maxn);
bool dfs(int current, int count)
{
    if (count == v)
        return true;

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = 1;
            if (dfs(neighbor, count + 1))
                return true;
            visited[neighbor] = 0; // backtrack
        }
    }

    return false;
}

bool hasHamiltonianPath()
{

    for (int start = 1; start <= v; ++start)
    {
        visited[start] = 1;
        if (dfs(start, 1))
            return true;
        visited[start] = 0;
    }

    return false;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> v >> e;
        for(int i = 1; i <= v; ++i)
        {
            adj[i].clear();
        }
        visited.assign(maxn, 0);
        for (int i = 1; i <= e; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (hasHamiltonianPath())
        {
            cout << "1" << "\n";
        }
        else
        {
            cout << "0" << "\n";
        }
    }
    return 0;
}