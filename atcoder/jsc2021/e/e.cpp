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

int main()
{
    int K;
    string S;
    cin >> K >> S;
    int N = S.size();
    vector<valarray<int>> c(N, valarray<int>(0, 26));

    rep(i, N){
        c[i][S[i] - 'a']++;
    }

    if(K > 20 || (K > 0 && (N >> (K - 1)) == 0) || (N >> K) == 1) {
        cout << "impossible\n";
        return 0;
    }

    int ans = 0, x = 0;

    for(; x < K; x++){
        const int L = N / 2;
        bool odd = (N % 2 == 1);

        rep(i, L){
            c[i] += c.back();
            c.pop_back();
        }

        if(odd){
            ans += (1 << x) - c.back().max();
            c.pop_back();
        }
        N = L;
    }

    if(N == 0){
        cout << ans << "\n";
        return 0;
    }

    const int L = N / 2;
    bool odd = (N % 2 == 1);

    int costDiff = INT32_MAX;

    rep(i, L){
        auto &a = c[i];
        auto &b = c.back();

        vi ia(26), ib(26);

        iota(rng(ia), 0);
        iota(rng(ib), 0);

        sort(rng(ia), [&](int x, int y){return a[x] > a[y];});
        sort(rng(ib), [&](int x, int y){return b[x] > b[y];});
        // partial_sort(ia.begin(), ia.begin() + 2, ia.end(), [&](int x, int y){return a[x] > a[y];});
        // partial_sort(ib.begin(), ib.begin() + 2, ib.end(), [&](int x, int y){return b[x] > b[y];});

        if(ia[0] != ib[0]){
            costDiff = 0;
        }

        ans += (1 << x) - a[ia[0]];
        ans += (1 << x) - b[ib[0]];

        chmin(costDiff, a[ia[0]] - a[ia[1]]);
        chmin(costDiff, b[ib[0]] - b[ib[1]]);

        c.pop_back();
    }
    if(odd) {
        ans += (1 << x) - c.back().max();
    }
    ans += costDiff;
    cout << ans << "\n";

    return 0;
}