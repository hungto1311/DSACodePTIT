#include <bits/stdc++.h>
using namespace std;
int n, k;
void generate(set<vector<int>> &res, vector<int> &cur, vector<int> &nums, int start_index)
{
    if (accumulate(cur.begin(), cur.end(), 0) > k)
    {
        return;
    }
    if (accumulate(cur.begin(), cur.end(), 0) == k)
    {
        // sort(cur.begin(), cur.end());
        res.insert(cur);
        return;
    }
    for (int i = start_index; i < n; ++i)
    {
        cur.push_back(nums[i]);
        generate(res, cur, nums, i);
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
        cin >> n >> k;
        vector<int> nums(n);
        for (int &x : nums)
            cin >> x;
        set<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        generate(res, cur, nums, 0);
        if (res.size() != 0)
        {
            cout << res.size() << " ";
            for (const auto &v : res)
            {
                cout << "{";
                for (int i = 0; i < v.size(); ++i)
                {
                    if (i != v.size() - 1)
                    {
                        cout << v[i] << " ";
                    }
                    else
                    {
                        cout << v[i];
                    }
                }
                cout << "} ";
            }
        }
        else
        {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}