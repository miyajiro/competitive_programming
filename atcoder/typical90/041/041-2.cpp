#include <bits/stdc++.h>
#include <atcoder/all>
#define fr first
#define sc second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i >= 1; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define snuke srand((unsigned)clock() + (unsigned)time(NULL));
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using namespace std;
using namespace atcoder;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vp = vector<P>;
using vlp = vector<LP>;
inline int getInt()
{
    int x;
    scanf("%d", &x);
    return x;
}
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

using Point = LP;

Point operator-(const Point &a, const Point &b)
{
    return Point(a.fr - b.fr, a.sc - b.sc);
}

using Polygon = vector<Point>;

ll cross(const Point &a, const Point &b)
{
    return a.fr * b.sc - a.sc * b.fr;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// 凸包
Polygon convex_hull(Polygon &G)
{
    sort(rng(G));

	// Step #2. 凸包を求める
	vector<Point> G1, G2, Totsuhou;
	G1.push_back(G[0]); G2.push_back(G[0]);
	G1.push_back(G[1]); G2.push_back(G[1]);
	for (int i = 2; i < sz(G); i++) {
		while (G1.size() >= 2 && cross(G1[G1.size() - 1] - G1[G1.size() - 2], G[i] - G1[G1.size() - 1]) <= 0) G1.pop_back();
		while (G2.size() >= 2 && cross(G2[G2.size() - 1] - G2[G2.size() - 2], G[i] - G2[G2.size() - 1]) >= 0) G2.pop_back();
		G1.push_back(G[i]);
		G2.push_back(G[i]);
	}
	for (int i = 0; i < G1.size(); i++) Totsuhou.push_back(G1[i]);
	for (int i = (int)G2.size() - 2; i >= 1; i--) Totsuhou.push_back(G2[i]);

    return Totsuhou;
}

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll latticeOnLine(Point p1, Point p2){
    ll dx = abs(p2.fr - p1.fr);
    ll dy = abs(p2.sc - p1.sc);
    return gcd(dx, dy) + 1;
}

ll N;
vl X, Y;

// S = i + b/2 - 1
// i + b = S + 1 + b/2

ll calc2S(Point p0, Point p1, Point p2){
    ll x1 = p1.fr - p0.fr;
    ll y1 = p1.sc - p0.sc;
    ll x2 = p2.fr - p0.fr;
    ll y2 = p2.sc - p0.sc;

    return abs(x1 * y2 - x2 * y1);
}

void solve()
{
    cin >> N;
    Polygon convexHull;

    rep(i, N){
        ll x, y;
        cin >> x >> y;
        convexHull.pb(Point(x, y));
    }

    convexHull = convex_hull(convexHull);
    ll C = sz(convexHull);

    ll b = 0;
    rep(i, C){ // i, i+1の間の格子点(i + 1含まない)
        b += latticeOnLine(convexHull[i], convexHull[(i + 1) % C]) - 1LL;
    }

    ll S_2 = 0;
    rep1(i, C - 2){
        S_2 += calc2S(convexHull[0], convexHull[i], convexHull[i+1]);
    }

    cout << (S_2 + 2 + b) / 2LL - N << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}