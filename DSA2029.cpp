#include <bits/stdc++.h>
using namespace std;

void ThapHaNoi(int n, char nguon, char trung_gian, char dich)
{
    if (n == 1)
    {
        cout << nguon << " -> " << dich << "\n";
        return;
    }
    ThapHaNoi(n - 1, nguon, dich, trung_gian);
    cout << nguon << " -> " << dich << "\n";
    ThapHaNoi(n - 1, trung_gian, nguon, dich);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ThapHaNoi(n, 'A', 'B', 'C');
    return 0;
}