#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> res;
// kiem tra du dieu kien 1 chuoi k A
bool validate(string s)
{
    int number_of_blocks = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'B')
        {
            continue;
        }
        else
        {
            int j = i;
            while (j < n && s[j] == 'A')
            {
                ++j;
            }
            if (j - i > k)
            {
                return false;
            }
            if (j - i == k)
            {
                ++number_of_blocks;
            }
            i = j - 1;
        }
    }
    return number_of_blocks == 1;
}

void generate(string curr, int i)
{
    if (i == n)
    {
        if (validate(curr))
        {
            res.push_back(curr);
        }
        return;
    }

    generate(curr + "A", i + 1);
    generate(curr + "B", i + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    generate("", 0);
    cout << res.size() << "\n";
    for (string &s : res)
    {
        cout << s << "\n";
    }
    return 0;
}