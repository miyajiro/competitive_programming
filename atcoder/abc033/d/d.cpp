#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder{};
using namespace atcoder;
using namespace std;

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
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d)
{
    return Point(real(p) * d, imag(p) * d);
}

istream &operator>>(istream &is, Point &p)
{
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream &operator<<(ostream &os, Point &p)
{
    return os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

// 点 p を反時計回りに theta 回転
Point rotate(Real theta, const Point &p)
{
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r)
{
    return (r * 180.0 / PI);
}

Real degree_to_radian(Real d)
{
    return (d * PI / 180.0);
}

// a-b-c の角度のうち小さい方を返す
Real get_angle(const Point &a, const Point &b, const Point &c)
{
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
    if (alpha > beta)
        swap(alpha, beta);
    Real theta = (beta - alpha);
    return min(theta, 2 * acos(-1) - theta);
}

namespace std
{
    bool operator<(const Point &a, const Point &b)
    {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}

struct Line
{
    Point a, b;

    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    Line(Real A, Real B, Real C) // Ax + By = C
    {
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            b = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p)
    {
        return os << p.a << " to " << p.b;
    }

    friend istream &operator>>(istream &is, Line &a)
    {
        return is >> a.a >> a.b;
    }
};

struct Segment : Line
{
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle
{
    Point p;
    Real r;

    Circle() = default;

    Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

Real cross(const Point &a, const Point &b)
{
    return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b)
{
    return real(a) * real(b) + imag(a) * imag(b);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 点の回転方向
int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if (cross(b, c) > EPS)
        return +1; // "COUNTER_CLOCKWISE"
    if (cross(b, c) < -EPS)
        return -1; // "CLOCKWISE"
    if (dot(b, c) < 0)
        return +2; // "ONLINE_BACK"
    if (norm(b) < norm(c))
        return -2; // "ONLINE_FRONT"
    return 0;      // "ON_SEGMENT"
}

ll ansDon = 0;
ll ansCho = 0;

double myAtan(Point a){
    if(a.imag() >= 0){
        return atan2(a.imag(), a.real());
    }
    return atan2(a.imag(), a.real()) + M_PI * 2;
}

bool cmp(const Point& a, const Point& b){ // a < bならtrue
    return myAtan(a) < myAtan(b);
}

void calc(int N, vi X, vi Y){ // (0, 0)を中心にいくつ直角、鈍角ができるか
    vector<Point> ps;
    rep(i, N){
        ps.pb(Point{X[i], Y[i]});
    }
    sort(rng(ps), cmp);
    rep(i, N){
        // show(ps[i]);
        ps.pb(ps[i]);
    }

    Point o = Point{0, 0};
    int l = 0, r = 0;
    Point p0 = ps[0];
    ll choDiff = 0;
    ll donDiff = 0;

    rep(i, N){
        chmax(l, i + 1);
        Point p = ps[i];
        while(l < i + N && ccw(o, p, ps[l]) == +1 && dot(p, ps[l]) > EPS){
            l++;
        }
        chmax(r, l);
        while(r < i + N && ccw(o, p, ps[r + 1]) == +1){
            r++;
        }

        // show(i);
        // show(l);
        // show(r);

        if(l == i + N || ccw(o, p, ps[l]) == -1){ // 鈍角直角作れない
            continue;
        }

        donDiff += r - l + 1;

        if(dot(p, ps[l]) == 0){ // lが直角
            donDiff--;
            choDiff++;
        }
    }

    // show(donDiff);
    // show(choDiff);

    ansDon += donDiff;
    ansCho += choDiff;
}


void solve(){
    int N;
    vi X, Y;

    cin >> N;
    rep(_, N){
        int x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }

    vi _X, _Y;
    rep(i, N){
        int gx = X[i];
        int gy = Y[i];
        _X = vi();
        _Y = vi();
        rep(j, N){
            if(i == j){
                continue;
            }
            _X.pb(X[j] - gx);
            _Y.pb(Y[j] - gy);
        }
        calc(N - 1, _X, _Y);
    }

    ll lN = N;
    ll ansEi = lN * (lN - 1LL) * (lN - 2LL) / 6LL - ansDon - ansCho;

    cout << ansEi << " " << ansCho << " " << ansDon << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}