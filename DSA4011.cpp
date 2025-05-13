#include <bits/stdc++.h>
using namespace std;

long long calculate(string s)
{
    long long ans = 0;
    for(char c : s)
    {
        ans = ans * 2 + (c == '1' ? 1 : 0);
    }
    return ans;
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
        string s1, s2;
        cin >> s1 >> s2;
        long long res = calculate(s1) * calculate(s2);
        cout << res << "\n";
    }
    return 0;
}