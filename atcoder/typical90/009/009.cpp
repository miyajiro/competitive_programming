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
#define v(T) vector<T>
#define vv(T) v(v(T))
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

using A_I = pair<double, int>; // 度数, インデックス

int N;
vl X, Y;
const double eps = 1e-10;
double PI = M_PI;

bool eq(double a, double b){
    if(a > b){
        swap(a, b);
    }
    return b - a < eps;
}

double arg(int X1, int Y1, int X2, int Y2){
    double abs1 = sqrt(X1*X1 + Y1 * Y1);
    double abs2 = sqrt(X2*X2 + Y2 * Y2);
    double vecDot = X1 * X2 + Y1 * Y2;
    return acos(vecDot / (abs1 * abs2));
}

bool detPlus(int X1, int Y1, int X2, int Y2){
    return (X1 * Y2 - Y1 * X2 >= 0);
}

double solve(int ni){
    int ox = X[ni];
    int oy = Y[ni];

    vi VX, VY;
    rep(i, N){
        VX.pb(X[i] - X[ni]);
        VY.pb(Y[i] - Y[ni]);
    }

    double ans_rad = 0.0;

    v(A_I) AIArray;
    rep(i, N){
        if(i == ni){
            continue;
        }

        double vx = VX[i];
        double vy = VY[i];

        double dosu;
        if(vx == 0.0){
            if(vy > 0.0){
                AIArray.pb(A_I(PI / 2, i));
            } else {
                AIArray.pb(A_I(3 * PI / 2, i));
            }
            continue;
        }
        double atanVal = atan(vy / vx);
        if(vy < 0.0){
            atanVal += PI;
        }

        AIArray.pb(A_I(atanVal, i));
    }
    int M = AIArray.size();

    sort(rng(AIArray));

    int rev_i = 0;
    A_I rev = AIArray[rev_i];
    int vxRev = VX[rev.sc];
    int vyRev = VY[rev.sc];

    rep(now_i, M){
        A_I now = AIArray[now_i];
        int vxNow = VX[now.sc];
        int vyNow = VY[now.sc];

        while(rev_i != now_i && detPlus(vxNow, vyNow, vxRev, vyRev)){
            rev_i = (rev_i + 1) % M;
            rev = AIArray[rev_i];
            vxRev = VX[rev.sc];
            vyRev = VY[rev.sc];
        }

        int rev_i_0 = (rev_i + M - 1) % M;
        int rev_i_1 = rev_i;

        A_I rev0 = AIArray[rev_i_0];
        A_I rev1 = AIArray[rev_i_1];

        int vx0 = VX[rev0.sc];
        int vy0 = VY[rev0.sc];

        int vx1 = VX[rev1.sc];
        int vy1 = VY[rev1.sc];

        chmax(ans_rad, arg(vxNow, vyNow, vx0, vy0));
        chmax(ans_rad, arg(vxNow, vyNow, vx1, vy1));
    }

    double ans = ans_rad * 180.0 / PI;
    return ans;
}

int main()
{
    cin >> N;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }

    double ans = 0.0;
    rep(i, N){
        chmax(ans, solve(i));
    }
    cout << ans << endl;

    return 0;
}