#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
// #define endl '\n'

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, caseNo = 1;
	cin >> t;
	while (t--)
	{
		long double a, b, c, d, d1, d2;
		cin >> a >> b >> c;
		// cout << a << " " << b << " " << c << endl;
		bool flag = true;
		if (b != 0)
		{
			d1 = (a * c) / b;
		}
		else
		{
			flag = false;
		}
		if (flag == false)
		{
			cout << "Case " << caseNo++ << ": -1" << endl;
			continue;
		}
		d2 = (a + d1) * (c + d1);

		if (b != d1)
		{
			d2 = d2 / (b - d1);
		}
		else
		{
			flag = false;
		}
		if (flag == false)
		{
			cout << "Case " << caseNo++ << ": -1" << endl;
			continue;
			;
		}

		d = d1 + d2;
		if (d < 0)
		{
			flag = false;
		}
		if (flag == false)
		{
			cout << "Case " << caseNo++ << ": -1" << endl;
			continue;
		}

		cout << "Case " << caseNo++ << ": ";
		cout << std::fixed << std::setprecision(12) << (d) << endl;
	}

	return 0;
}
