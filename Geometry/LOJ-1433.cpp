#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

long double getDistance(long double x1, long double x2, long double y1, long double y2)
{
	long double ans = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(ans);
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
		long double ox, oy, ax, ay, bx, by;
		cin >> ox >> oy >> ax >> ay >> bx >> by;
		long double oa = getDistance(ox, ax, oy, ay);
		long double ob = getDistance(ox, bx, oy, by);
		long double ab = getDistance(ax, bx, ay, by);

		long double angle = (oa * oa + ob * ob - ab * ab) / (2 * oa * ob);
		angle = acos(angle);

		cout << "Case " << caseNo++ << ": ";
		cout << std::fixed << std::setprecision(12) << (oa * angle) << endl;
	}

	return 0;
}
