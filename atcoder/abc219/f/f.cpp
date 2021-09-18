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

ll K;
int N;
string S;
vl AX, AY;
vlp vec;
vector<vlp> pat;

int hantei(ll sx, ll sy) {
	int pos1 = lower_bound(rng(vec), make_pair(sx, sy)) - vec.begin();
	if (pos1 == vec.size() || vec[pos1] != make_pair(sx, sy)) return -1;
	return pos1;
}

ll solve_naive(){
    ll res = 0;
    set<LP> st;
    rep(i, N + 1){
        LP lp = LP(AX[i], AY[i]);
        if(st.find(lp) == st.end()){
            res++;
        }
        st.insert(lp);
    }
    return res;
}

ll calc(ll pos){
    vl Z;
    rep(j, pat[pos].size()){
        Z.eb(pat[pos][j].fr);
        Z.eb(pat[pos][j].sc);
    }
    sort(rng(Z));
    uni(Z);

    vl cnt(sz(Z) + 2, 0);
    rep(j, pat[pos].size()){
        ll pos1 = lower_bound(rng(Z), pat[pos][j].fr) - Z.begin();
        ll pos2 = lower_bound(rng(Z), pat[pos][j].sc) - Z.begin();
        cnt[pos1] += 1LL;
        cnt[pos2] -= 1LL;
    }
    rep1(j, sz(cnt) - 1LL){
        cnt[j] += cnt[j - 1];
    }

    ll res = 0;
    rep(i, sz(cnt)){
        if(cnt[i] > 0){
            res += (Z[i + 1] - Z[i]);
        }
    }
    return res;
}

void solve()
{
    cin >> S;
    cin >> K;
    N = S.size();

    AX = vl(N + 1, 0);
    AY = vl(N + 1, 0);

    rep(i, N){
        AX[i + 1] = AX[i];
        AY[i + 1] = AY[i];
        if (S[i] == 'U') AY[i + 1] += 1;
		if (S[i] == 'D') AY[i + 1] -= 1;
		if (S[i] == 'R') AX[i + 1] += 1;
		if (S[i] == 'L') AX[i + 1] -= 1;
    }

    if (AX[N] < 0){
        rep(i, N + 1){
            AX[i] *= -1LL;
        }
    }
    if (AY[N] < 0){
        rep(i, N + 1){
            AY[i] *= -1LL;
        }
    }
    if (AX[N] < AY[N]){
        rep(i, N + 1){
            swap(AX[i], AY[i]);
        }
    }

    ll minX = 0;
    ll minY = 0;
    rep(i, N + 1){
        chmin(minX, AX[i]);
    }
    rep(i, N + 1){
        chmin(minY, AY[i]);
    }
    rep(i, N + 1){
        AX[i] -= minX;
        AY[i] -= minY;
    }

    ll vx = AX[N] - AX[0];
    ll vy = AY[N] - AY[0];

    if(vx == 0 && vy == 0){
        cout << solve_naive() << "\n";
        return;
    }

    rep(i, N){
        ll ux = AX[i] % vx;
        ll uy = AY[i] - (AX[i] / vx) * vy;
        vec.eb(LP(ux, uy));
    }

    sort(rng(vec));
    uni(vec);

    pat = vector<vlp>(sz(vec));
    rep(i, N){
        ll ux = AX[i] % vx;
        ll uy = AY[i] - (AX[i] / vx) * vy;
        ll pos1 = lower_bound(rng(vec), LP(ux, uy)) - vec.begin();

        ll cl = AX[i] / vx;
        ll cr = cl + K;
        if(i == 0){
            cr += 1;
        }
        pat[pos1].eb(LP(cl, cr));
    }

    ll ans = 0;

    rep(i, sz(vec)){
        ll ux = vec[i].fr;
        ll uy = vec[i].sc;
		ll pos = hantei(ux % vx, uy - (ux / vx) * vy);
        if(pos >= 0){
            ans += calc(pos);
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