#include <bits/stdc++.h>
using namespace std;
string next(string s, int n)
{
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        --i;
    }
    if (i == -1)
    {
        return "BIGGEST";
    }
    else
    {
        int j = n - 1;
        while (s[i] >= s[j])
        {
            --j;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return s;
    }
}
// 279134399742
// 279134392479
// 279134423799
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = next(s, s.size());
        cout << n << " " << ans << "\n";
    }

    return 0;
}