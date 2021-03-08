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

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a - (a / b) * b);
}

/*
二元一次不定方程式 ax+by=c(a≠0かつb≠0) を解く
初期化すると、x=x0+m*b,y=y0-m*aで一般解が求められる(m=0で初期化)
llは32bit整数まで→超えたらPythonに切り替え
*/
struct LDE{
    ll a,b,c,x,y;
    ll m=0;
    bool check=true;//解が存在するか

    //初期化
    LDE(ll a_,ll b_,ll c_): a(a_),b(b_),c(c_){
        ll g=gcd(a,b);
        if(c%g!=0){
            check=false;
        }else{
            //ax+by=gの特殊解を求める
            extgcd(abs(a),abs(b),x,y);
            if(a<0)x=-x;
            if(b<0)y=-y;

            if(abs(x) >= abs(y)){
                ll num = abs(x) - abs(y) / b;
                if(x > 0){
                    x -= num * b;
                    y += num * a;
                } else {
                    x += num * b;
                    y -= num * a;
                }
            } else {
                ll num = abs(y) - abs(x) / a;
                if(y > 0){
                    x += num * b;
                    y -= num * a;
                } else {
                    x -= num * b;
                    y += num * a;

                }
            }

            //ax+by=cの特殊解を求める(オーバフローに注意！)
            x*=c/g;y*=c/g;
            //一般解を求めるために割る
            a/=g;b/=g;
        }
    }

    //拡張ユークリッドの互除法
    //返り値:aとbの最大公約数
    ll extgcd(ll a,ll b,ll &x0,ll &y0){
        if(b==0){
            x0=1;
            y0=0;
            return a;
        }
        ll d=extgcd(b,a%b,y0,x0);
        y0-=a/b*x0;
        return d;
    }

    //パラメータmの更新(書き換え)
    void m_update(ll m_){
        x+=(m_-m)*b;
        y-=(m_-m)*a;
        m=m_;
    }
};
const ll INF = INT64_MAX;

void solve(){
    ll _X, _Y, _P, _Q;
    ll ans = INF;

    cin >> _X >> _Y >> _P >> _Q;

    rep(t, _Y){
        rep(q, _Q){
            // 停車してt秒目、眠ってq秒目
            ll a = 2LL * _X + 2LL * _Y;
            ll b = -_P - _Q;
            ll c = _P + q - _X - t;

            LDE lde(a, b, c);

            if(!lde.check){
                continue;
            }

            ll x = lde.x;
            ll y = lde.y; // x, yがともに正であることが条件。

            b = -b;
            // xにb, yにaを施す。

            if(x < 0){
                ll num = ((-x) / b) + 3LL;
                x += num * b;
                y += num * a;
            }

            if(y < 0){
                ll num = ((-y) / a) + 3LL;
                x += num * b;
                y += num * a;
            }

            // これでx, y両方正。

            ll num = min(x / b, y / a);

            x -= num * b;
            y -= num * a;

            ll tmp_ans = (_P + _Q) * y + _P + q;

            chmin(ans, tmp_ans);
        }
    }

    if(ans == INF){
        puts("infinity");
    } else {
        cout << ans << endl;
    }
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        solve();
    }

    return 0;
}