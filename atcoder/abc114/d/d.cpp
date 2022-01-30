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
#define show(x) cerr << #x << " = " << x << endl;
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

int N;
vp primes;

void solve()
{
    cin >> N;

    srep(i, 2, N + 1){
        rep1(j, i - 1){
            if(j > 1 && i % j == 0){
                break;
            }

            if(j == i - 1){
                int p = i;

                int cnt = 0;
                while(p <= N){
                    cnt += N / p;
                    p *= i;
                }
                primes.eb(P(i, cnt));
                // show(primes.back().fr);
                // show(primes.back().sc);
            }
        }
    }

    ll ans = 0;
    // ^74
    for(auto p : primes){
        int k = p.sc;
        if(k >= 74){
            ans++;
        }
    }


    for(auto p1 : primes){
        for(auto p2 : primes){
            if(p1 == p2){
                continue;
            }

            int k1 = p1.sc;
            int k2 = p2.sc;

            // ^24 ^2
            if(k1 >= 24 && k2 >= 2){
                ans++;
            }

            // ^14 ^4
            if(k1 >= 14 && k2 >= 4){
                ans++;
            }
        }
    }

    // ^4 ^4 ^2
    for(auto p1 : primes){
        for(auto p2 : primes){
            for(auto p3 : primes){
                if(p1 >= p2 || p1 == p2 || p2 == p3 || p3 == p1){
                    continue;
                }

                int k1 = p1.sc;
                int k2 = p2.sc;
                int k3 = p3.sc;

                if(k1 >= 4 && k2 >= 4 && k3 >= 2){
                    ans++;
                }
            }
        }
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