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

ll N;
vl A;
ll ans = 0LL;
priority_queue<LP> lq, rq;
bool used[400000];

int main()
{
    cin >> N;
    N *= 2LL;
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
        used[i] = false;
    }

    rep(i, N){
        if(i < N / 2LL){
            lq.push(LP(A[i], i));
        } else {
            rq.push(LP(A[i], -i));
        }
    }

    ll al = N / 2LL - 1LL;
    ll ar = N / 2LL;

    rep(_, N / 2LL){
        // al, arを適切にする。
        while(used[ar]){
            ar++;
        }
        while(used[al]){
            al--;
        }

        LP p;

        LP rp = rq.top();
        while(used[rp.sc]){
            rq.pop();
            rp = rq.top();
            rp.sc = -p.sc;
        }

        LP lp = lq.top();
        while(used[rp.sc]){
            lq.pop();
            lp = lq.top();
        }

        if(A[al] < A[ar] || (A[al] == A[ar] && rp.fr >= lp.fr)){ // 右の方が強い場合
            p = rq.top();
            rq.pop();
            p.sc = -p.sc;

            while(used[p.sc]){
                p = rq.top();
                p.sc = -p.sc;
                rq.pop();
            }

            // 右取る
            ans += p.fr;
            used[p.sc] = true;

            used[al] = true; // 左取らせる。
            al--;
        } else {
            p = lq.top();
            lq.pop();
            while(used[p.sc]){
                p = lq.top();
                lq.pop();
            }

            // 左取る
            ans += p.fr;
            used[p.sc] = true;

            used[ar] = true; // 右取らせる。
            ar++;
        }
    }

    cout << ans << endl;

    return 0;
}