#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int a[16][16];
int dp[35000];
int h[16];
int n;

ll func(int mask)
{
	if (mask == ((1 << n) - 1))
		return 0;
	if (dp[mask] != -1)
		return dp[mask];

	vector<int> ava;
	for (int i = 0; i < 32; i++)
	{
		if ((1LL << i) & (mask))
		{
			ava.push_back(i + 1);
		}
	}

	ll ans = 1e9;
	for (int i = 0; i < n; i++)
	{
		if ((1LL << i) & (mask)) // already gone
			continue;
		ans = min(ans, h[i + 1] + func(mask | (1 << i)));
		if (ava.empty() == false)
		{
			for (int j = 0; j < ava.size(); j++)
			{
				int idx = ava[j];
				if (a[idx][i + 1] == 0)
					continue;
				int koto = a[idx][i + 1];
				ans = min(ans, ((h[i + 1] + koto - 1) / koto) + func(mask | (1 << i)));
			}
		}
	}
	return dp[mask] = ans;
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
			cin >> h[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				char c;
				cin >> c;
				a[i][j] = c - '0';
			}
		}
		ll ans = func(0);
		cout << "Case " << caseNo++ << ": " << ans << endl;
	}

	return 0;
}
