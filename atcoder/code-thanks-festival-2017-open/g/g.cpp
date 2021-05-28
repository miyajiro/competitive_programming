#include <bits/stdc++.h>
// #include <atcoder/all>
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
// using namespace atcoder;
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

int N, M;
int N1, N2;
vi A, B;
vi n12AvaliableS2;

bool ok(ll s){
    rep(i, M){
        int a = A[i];
        int b = B[i];
        if(((s >> a) & 1LL) == 1LL && ((s >> b) & 1LL) == 1LL){
            return false;
        }
    }
    return true;
}

int calcS2(int s1){
    int res = bn(N2);
    rep(ni1, N1){
        if(((s1 >> ni1) & 1) == 1){
            res &= n12AvaliableS2[ni1];
        }
    }
    return res;
}

void solve()
{
    cin >> N >> M;
    N1 = N / 2;
    N2 = N - N1;

    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b){
            swap(a, b);
        }
        A.pb(a);
        B.pb(b);
    }

    n12AvaliableS2 = vi(N1, bn(N2));
    rep(n1, N1){
        rep(mi, M){
            if(A[mi] == n1 && N1 <= B[mi]){
                int b2 = B[mi] - N1;

                n12AvaliableS2[n1] &= (~(1 << b2));
            }
        }
    }

    vi dp1(1 << N1, 0);
    vi dp2(1 << N2, 0);

    rep(s1, 1 << N1){
        if(ok(s1)){
            dp1[s1] = pcnt(s1);
            continue;
        }

        rep(ni, N1){
            if(((s1 >> ni) & 1) == 1){
                chmax(dp1[s1], dp1[s1 ^ (1 << ni)]);
            }
        }
    }

    rep(s2, 1 << N2){
        ll lls2 = s2;
        if(ok(lls2 << N1)){
            dp2[s2] = pcnt(s2);
            continue;
        }

        rep(ni, N2){
            if(((s2 >> ni) & 1) == 1){
                chmax(dp2[s2], dp2[s2 ^ (1 << ni)]);
            }
        }
    }

    int ans = 0;
    rep(s1, 1 << N1){
        int s2 = calcS2(s1);
        chmax(ans, dp1[s1] + dp2[s2]);
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}