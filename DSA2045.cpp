#include <bits/stdc++.h>
using namespace std;

void generate(vector<string> &res, string &cur, string s, int start_index)
{
    res.push_back(cur);
    for (int i = start_index; i < s.size(); ++i)
    {
        cur += s[i];
        generate(res, cur, s, i + 1);
        cur.pop_back();
    }
}

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
        sort(s.begin(), s.end());
        vector<string> res;
        string cur;
        generate(res, cur, s, 0);
        for (string &s : res)
        {
            cout << s << " ";
        }
        cout << "\n";
    }
    return 0;
}