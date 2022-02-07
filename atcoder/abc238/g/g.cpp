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
#define show(x) cerr << #x << " = " << x << "\n";
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

int N, Q;
vi A, L, R;
vi imosA_NG;
vvi imosA_OK;
vi primes;
vi okPrimes;
vi okPrimes2I;

map<int, int> prime2I;
using vvp = vector<vp>;
vvp bunkaiA;

void solve()
{
    cin >> N >> Q;
    vector<bool> isPrime(1000001, true);

    rep(i, N){
        int a;
        cin >> a;
        A.eb(a);
    }
    rep(i, Q){
        int l, r;
        cin >> l >> r;
        L.eb(l);
        R.eb(r);
    }

    isPrime[0] = isPrime[1] = false;
    srep(i, 2, 1000001){
        if(!isPrime[i]){
            continue;
        }

        prime2I[i] = sz(primes);
        primes.eb(i);

        for(int j = i * 2; j <= 1000000; j += i){
            isPrime[j] = false;
        }
    }

    int M = sz(primes);
    vi primeCnt(M, 0);
    vector<bool> isOK(M, false);
    bunkaiA = vvp(N);

    rep(i, N){
        int a = A[i];
        rep(pi, M){
            int p = primes[pi];
            if(p > a){
                break;
            }

            if(a % p == 0){
                a /= p;
                int cnt = 1;
                while(a % p == 0){
                    cnt++;
                    a /= p;
                }

                bunkaiA[i].eb(P(pi, cnt));
                primeCnt[pi] += cnt;
            }
        }
    }

    rep(m, M){
        if(primeCnt[m] >= 3){
            isOK[m] = true;
            okPrimes.eb(primes[m]);
        }
    }

    int K = sz(okPrimes);

    okPrimes2I = vi(K);
    rep(i, K){
        okPrimes2I[okPrimes[i]] = i;
    }

    // imosA_NG, imosA_OK
    imosA_NG = vi(N + 2, 0);
    imosA_OK = vvi(N + 2, vi(K, 0));
    rep(ai, N){
        for(auto f : bunkaiA[ai]){
            int pi = f.fr;
            int cnt = f.sc;
            if(!isOK[pi]){
                imosA_NG[ai + 1] += 1;
                imosA_NG[ai + 2] -= 1;
                continue;
            }

            int p = primes[pi];
            int oki = okPrimes2I[p];
            imosA_OK[ai + 1][oki] += cnt;
        }
    }

    rep1(i, N + 1){
        imosA_NG[i] += imosA_NG[i - 1];
        rep(oki, K){
            imosA_OK[i][oki] += imosA_OK[i - 1][oki];
        }
    }

    rep(i, Q){
        int l = L[i];
        int r = R[i];

        if(imosA_NG[r] - imosA_NG[l - 1] > 0){
            cout << "No\n";
            continue;
        }

        bool ok = true;
        rep(oki, K){
            int cnt = imosA_OK[r][oki] - imosA_OK[l - 1][oki];
            if(cnt % 3 != 0){
                ok = false;
            }
        }
        if(ok){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}