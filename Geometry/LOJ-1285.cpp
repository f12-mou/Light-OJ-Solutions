#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
const double eps = 1e-6;
inline int dcmp(double x)
{
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}

struct Point
{
	ll x, y;
	double dist;
	int id;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}

	bool operator==(const Point &u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator!=(const Point &u) const { return !(*this == u); }
	bool operator<(const Point &u) const { return dcmp(x - u.x) < 0 || (dcmp(x - u.x) == 0 && dcmp(y - u.y) < 0); }
	bool operator>(const Point &u) const { return u < *this; }
	bool operator<=(const Point &u) const { return *this < u || *this == u; }
	bool operator>=(const Point &u) const { return *this > u || *this == u; }
	Point operator+(const Point &u) { return Point(x + u.x, y + u.y); }
	Point operator-(const Point &u) { return Point(x - u.x, y - u.y); }
	Point operator*(const ll u) { return Point(x * u, y * u); }
	ll operator*(const Point &u) { return x * u.y - y * u.x; }
};

typedef Point Vector;
Point pivot;
double getCross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

// 2. Sorting points based on polar angle
bool sgn(Point p) { return p.y < 0 || (p.y == 0 && p.x < 0); }
bool operator<(Point p, Point q)
{
	double k = getCross(p - pivot, q - pivot);
	if (fabs(k) < eps)
	{
		return p.dist < q.dist;
	}
	else
	{
		return k > 0;
	}
}

Point arr[2007];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, caseNo = 1;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<Point> vec;
		ll x, y;
		Point p;
		map<pair<ll, ll>, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			arr[i].x = x;
			arr[i].y = y;
			arr[i].id = i;
			if (i == 0)
			{
				p = arr[i];
			}
			else
			{
				if (y < p.y)
				{
					p = arr[i];
				}
				else if (y == p.y)
				{
					if (x < p.x)
					{
						p = arr[i];
					}
				}
			}
		}
		cout << "Case " << caseNo++ << ":" << endl;
		bool jhamela = true;
		for (int i = 2; i < n; i++)
		{
			if ((arr[0].y - arr[1].y) * (arr[0].x - arr[i].x) != (arr[0].y - arr[i].y) * (arr[0].x - arr[1].x))
			{
				jhamela = false;
				break;
			}
		}
		if (jhamela == true)
		{

			cout << "Impossible" << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			double here = (p.x - arr[i].x) * (p.x - arr[i].x) + (p.y - arr[i].y) * (p.y - arr[i].y);
			here = sqrt(here);
			arr[i].dist = here;
		}
		pivot = p;
		// cout << "pivot " << p.x << " " << p.y << endl;
		sort(arr, arr + n);
		// last er angle e bhejal
		// vector<Point> vec;
		vec.push_back(arr[n - 1]);
		for (int i = n - 2; i >= 0; i--)
		{
			if (pivot == arr[i])
				break;
			if (getCross(arr[i] - pivot, arr[n - 1] - pivot) == 0)
			{
				// equal
				vec.push_back(arr[i]);
			}
			else
				break;
		}
		int baad = (int)vec.size();
		int total = n - baad;

		for (int i = 0; i < total; i++)
		{
			cout << arr[i].id << " ";
		}
		for (int i = 0; i < baad; i++)
		{
			cout << vec[i].id << " ";
		}
		cout << endl;
	}

	return 0;
	//- 1, 2 0, 1 1, 0 2, 1 3, 2 2, 3 1, 4 0, 3
}
// https://reponroy.wordpress.com/2015/10/31/lightoj-1285-drawing-simple-polygon/