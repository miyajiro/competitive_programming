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

using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

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

int D;
vi P;
vi C;
int G;

int main()
{
    cin >> D >> G;
    rep(i, D){
        int p, c;
        cin >> p >> c;
        P.pb(p);
        C.pb(c);
    }

    int ans = 1000;

    rep(s, 1 << D){ // 該当するコンプリートボーナスをもらう場合。
        int cnt = 0;
        int score = G;

        rep(i, D){
            if((s >> i) % 2 == 1){
                cnt += P[i];
                score -= (i + 1) * 100 * P[i] + C[i];
            }
        }

        rrep(i, D){
            if(score <= 0){
                break;
            }
            if((s >> i) % 2 == 1){
                continue;
            }

            int monoScore = (i + 1) * 100;
            int tokuKosu = min(P[i], ((score + 1) / monoScore));
            cnt += tokuKosu;
            score -= tokuKosu * monoScore;
        }

        // cout << "s=" << s << ", cnt=" << cnt << endl;
        chmin(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}