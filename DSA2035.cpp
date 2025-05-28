#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> strings;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        strings.push_back(s);
    }
    vector<int> index(k);
    iota(index.begin(), index.end(), 0);
    long long smallest = LONG_LONG_MAX;
    do
    {
        vector<long long> curr;
        for (string &s : strings)
        {
            string new_s;
            for (int p : index)
            {
                new_s += s[p];
            }
            curr.push_back(stol(new_s));
        }
        auto maxn_it = *max_element(curr.begin(), curr.end());
        auto minn_it = *min_element(curr.begin(), curr.end());
        long long ans = maxn_it - minn_it;
        smallest = min(smallest, ans);
    } while (next_permutation(index.begin(), index.end()));
    cout << smallest << "\n";
    return 0;
}