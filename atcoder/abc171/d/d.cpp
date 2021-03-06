#include <bits/stdc++.h>
#define fr first
#define sc second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

int main()
{
    int N;
    vi A;
    int Q;
    vi B, C;
    vi cnt(100001, 0);
    ll sum;

    cin >> N;
    rep(i, N)
    {
        int x;
        cin >> x;
        sum += x;
        A.pb(x);
        cnt[x]++;
    }

    cin >> Q;
    rep(i, Q)
    {
        int b, c;
        cin >> b >> c;
        B.pb(b);
        C.pb(c);
        sum += (c - b) * cnt[b];
        cnt[c] += cnt[b];
        cnt[b] = 0;
        cout << sum << endl;
    }

    return 0;
}