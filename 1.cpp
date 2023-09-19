#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void solve(vector<int> heights, int d, int n)
{
    int ct, fl = 0;
    sort(heights.begin(), heights.end());

    if (d % 2 != 0)
        ct = 1;
    else
        ct = 2;

    int i = -1;

    while (i < n)
    {
        if (heights[++i] != heights[n - 1])
        {
            fl = 1;
            break;
        }
        else
            i++;
    }

    if (fl)
    {
        heights[i] += ct;
        ans++;
    }

    if (fl)
        solve(heights, d + 1, n);
    else
        return;
}

int main()
{
    vector<int> height;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        height.push_back(a);
    }
    solve(height, 1, n);
    cout << ans;

    return 0;
}