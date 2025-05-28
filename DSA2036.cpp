#include <bits/stdc++.h>
using namespace std;
int n;

void generate(vector<vector<int>> &res, vector<int> &cur, vector<int> &nums, int start_index)
{
    if (accumulate(cur.begin(), cur.end(), 0) % 2 == 1)
    {
        res.push_back(cur);
    }
    for (int i = start_index; i < n; ++i)
    {
        cur.push_back(nums[i]);
        generate(res, cur, nums, i + 1);
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
        cin >> n;
        vector<int> nums(n);
        vector<vector<int>> res;
        vector<int> cur;
        for (int &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end(), greater<int>());
        generate(res, cur, nums, 0);
        for (vector<int> &v : res)
        {
            sort(v.begin(), v.end(), greater<int>());
        }
        sort(res.begin(), res.end());
        for (vector<int> &v : res)
        {
            for (int x : v)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}