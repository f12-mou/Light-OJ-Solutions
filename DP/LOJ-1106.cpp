#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n, h;
int initial[28], kombe[28], transition[28];

int dp[26][195];
int tt[26][195];

int func(int pos, int left)
{
	if (pos == (n + 1) || left <= 0)
		return 0;
	if (dp[pos][left] != -1)
		return dp[pos][left];

	int &ret = dp[pos][left];
	ret = 0;
	// i am not bound to spend time here
	ret = func(pos + 1, left - transition[pos]);

	int rem = initial[pos];
	int total = 0;

	for (int i = 1; i <= 1005; i++)
	{
		// time checking
		if (left - i < 0)
		{
			break;
		}
		rem = initial[pos] - ((i - 1) * kombe[pos]);
		if (rem <= 0)
			rem = 0;
		total += rem;

		int received_val = total + func(pos + 1, left - transition[pos] - i);
		// cout << "pos left val " << pos << " " << left << " " << received_val << endl;
		if (received_val >= ret)
		{
			ret = received_val;
			tt[pos][left] = i;
		}
	}
	return ret;
}

void print(int pos, int left)
{
	if (pos == (n + 1))
		return;
	if (left <= 0)
	{
		for (int i = pos; i < n; i++)
		{
			cout << 0 << ", ";
		}
		cout << 0;
		return;
	}
	if (pos == n)
	{
		cout << (tt[pos][left] * 5);
		return;
	}
	cout << (tt[pos][left] * 5) << ", ";
	print(pos + 1, left - transition[pos] - tt[pos][left]);
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
		memset(tt, 0, sizeof(tt));
		cin >> n >> h;
		for (int i = 1; i <= n; i++)
		{
			cin >> initial[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> kombe[i];
		}
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> transition[i];
		}
		transition[n] = 0;
		int ans = func(1, h * 12);
		cout << "Case " << caseNo++ << ": " << endl;
		print(1, h * 12);
		cout << endl;
		cout << "Number of fish expected: " << ans << endl;
	}

	return 0;
}
