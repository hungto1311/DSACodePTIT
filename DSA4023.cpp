#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int &x : nums) cin >> x;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int j = 1;
        for(int i = 0; i < n; ++i)
        {
            while(j < n && nums[j] - nums[i] < k)
            {
                j++;
            }
            ans += max(0, j - i - 1);
        }
        cout << ans << "\n";
    }

    return 0;
}