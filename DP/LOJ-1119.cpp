#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n;
int a[15][15];
int dp[16390];

int getCost(int idx, int mask)
{
	ll total = a[idx][idx]; // base price
	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & (mask))
		{
			int xtra = a[idx][i + 1];
			total += xtra;
		}
	}
	return total;
}

int func(int mask)
{
	if (mask == ((1LL << n) - 1))
		return 0;
	if (dp[mask] != -1)
		return dp[mask];

	int ret = 1e10;
	for (int i = 0; i < n; i++)
	{
		if (((1 << i) & mask) == 0)
		{
			ret = min(ret, getCost(i + 1, mask) + func(mask | (1LL << i)));
		}
	}
	return dp[mask] = ret;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, caseNo = 1;
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
			}
		}
		ll ans = func(0);
		cout << "Case " << caseNo++ << ": " << ans << endl;
	}

	return 0;
}
