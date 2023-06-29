#include <bits/stdc++.h>

using namespace std;

vector<int> ul;

int dp[15][2][2];

long long dfs(int i, int s, int f)
{
    if (i == ul.size())
        return 1;
    if (dp[i][s][f] != -1)
        return dp[i][s][f];
    long long ans = 0;
    if (s == 0)
    {
        ans += dfs(i + 1, 0, 1);
    }
    if (f)
    {
        ans += 2 * dfs(i + 1, 1, 1);
    }
    else
    {
        if (ul[i] == 7)
            ans += dfs(i + 1, 1, 0) + dfs(i + 1, 1, 1);
        else
            ans += dfs(i + 1, 1, 0);
    }
    return dp[i][s][f] = ans;
}

int main()
{
    long long n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    while (n)
    {
        ul.push_back(n % 10);
        n = n / 10;
    }
    reverse(ul.begin(), ul.end());
    cout << dfs(0, 0, 0) - 1 << endl;
}