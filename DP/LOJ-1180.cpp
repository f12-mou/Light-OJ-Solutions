#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

int n, m;
int arr1[105], arr2[105];
int midNow;
int dp[105][105][105];

int func2(int pos, int task1, int task2)
{
	if (task1 == 0 && task2 == 0)
	{
		return dp[pos][task1][task2] = 1;
	}
	if (pos == n + 1)
	{
		if (task1 == 0 && task2 == 0)
		{
			return dp[pos][task1][task2] = 1;
		}
		else
		{
			return dp[pos][task1][task2] = 0;
		}
	}
	if (dp[pos][task1][task2] != -1)
	{
		return dp[pos][task1][task2];
	}
	int &ret = dp[pos][task1][task2];
	ret = 0;
	for (int i = 0; i <= task1; i++)
	{
		int first = i;
		int first_time = first * arr1[pos];
		if (first_time > midNow)
			break;
		int sec_time = midNow - first_time;
		int sec = (sec_time) / (arr2[pos]);
		ret = ret | func2(pos + 1, max(task1 - first, 0LL), max(0LL, task2 - sec));
	}
	return ret;
}
int func(int mid)
{
	midNow = mid;
	for (int i = 0; i <= n + 2; i++)
	{
		for (int j = 0; j <= m + 2; j++)
		{
			for (int k = 0; k <= m + 2; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = func2(1, m, m);
	return ans;
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr1[i] >> arr2[i];
		}
		int low = 0, high = 50005, mid, ans;
		while (low <= high)
		{
			mid = (low + high) / 2;
			midNow = mid;
			if (func(mid) == true)
			{
				ans = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		cout << "Case " << caseNo++ << ": " << ans << endl;
	}

	return 0;
}
