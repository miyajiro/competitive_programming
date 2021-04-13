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

int N, C;
int D[31][31];
int c[500][500];
vi s[3]; // 色
int iwa[3][31];

int main()
{
    cin >> N >> C;
    rep(i, C){
        rep(j, C){
            cin >> D[i][j];
        }
    }
    rep(i, N){
        rep(j, N){
            cin >> c[i][j];
            s[(i + j) % 3].pb(c[i][j]);
        }
    }

    rep(num, 3){
        rep1(c, C){
            rep(si, s[num].size()){
                int oldC = s[num][si];
                iwa[num][c] += D[oldC-1][c-1];
            }
        }
    }

    int ans = 0xfffffff;

    rep1(_c, C){
        cerr << "iwa[0][" << _c << "]=" << iwa[0][_c] << endl;
        cerr << "iwa[1][" << _c << "]=" << iwa[1][_c] << endl;
        cerr << "iwa[2][" << _c << "]=" << iwa[2][_c] << endl;
    }

    rep1(c0, C){
        rep1(c1, C){
            rep1(c2, C){
                if(c1 == c2 || c2 == c0 || c0 == c1){continue;}
                chmin(ans, iwa[0][c0] + iwa[1][c1] + iwa[2][c2]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}