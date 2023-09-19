#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n;
int a[1005];

int dp[1005][2];

int func(int pos, int first_taken)
{
	if (pos > n)
	{
		return 0;
	}
	if (dp[pos][first_taken] != -1)
	{
		return dp[pos][first_taken];
	}
	int &ret = dp[pos][first_taken];
	ret = 0;
	if (pos == 1)
	{
		// taken
		ret = max(ret, a[pos] + func(pos + 2, 1));
		// not taken
		ret = max(ret, func(pos + 1, first_taken));
	}
	else if (pos == n)
	{
		if (first_taken == 0)
		{
			ret = max(ret, a[pos] + func(pos + 2, first_taken));
		}
		else
		{
			ret = max(ret, func(pos + 2, first_taken));
		}
	}
	else
	{
		ret = max(ret, a[pos] + func(pos + 2, first_taken));
		ret = max(ret, func(pos + 1, first_taken));
	}
	return ret;
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
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if (n == 2)
		{
			cout << "Case " << caseNo++ << ": " << max(a[1], a[2]) << endl;
		}
		else
		{
			int ans = func(1, 0);
			cout << "Case " << caseNo++ << ": " << ans << endl;
		}
	}

	return 0;
}
