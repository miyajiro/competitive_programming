#include <bits/stdc++.h>
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

ll N, K;
vl X1, Y1, Z1, X2, Y2, Z2;
vl cX1, cY1, cZ1, cX2, cY2, cZ2;
vl Xs, Ys, Zs;
int imos[101][101][101];

void solve()
{
    cin >> N >> K;
    rep(i, N){
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >>  x2 >> y2 >> z2;
        X1.pb(x1);
        Y1.pb(y1);
        Z1.pb(z1);
        X2.pb(x2);
        Y2.pb(y2);
        Z2.pb(z2);

        Xs.pb(x1);
        Ys.pb(y1);
        Zs.pb(z1);
        Xs.pb(x2);
        Ys.pb(y2);
        Zs.pb(z2);
    }
    sort(rng(Xs));
    sort(rng(Ys));
    sort(rng(Zs));
    uni(Xs);
    uni(Ys);
    uni(Zs);

    rep(i, N){
        cX1.pb(lower_bound(rng(Xs), X1[i]) - Xs.begin());
        cY1.pb(lower_bound(rng(Ys), Y1[i]) - Ys.begin());
        cZ1.pb(lower_bound(rng(Zs), Z1[i]) - Zs.begin());
        cX2.pb(lower_bound(rng(Xs), X2[i]) - Xs.begin());
        cY2.pb(lower_bound(rng(Ys), Y2[i]) - Ys.begin());
        cZ2.pb(lower_bound(rng(Zs), Z2[i]) - Zs.begin());
        imos[cX1[i]][cY1[i]][cZ1[i]]++;
        imos[cX1[i]][cY1[i]][cZ2[i]]--;
        imos[cX1[i]][cY2[i]][cZ1[i]]--;
        imos[cX1[i]][cY2[i]][cZ2[i]]++;
        imos[cX2[i]][cY1[i]][cZ1[i]]--;
        imos[cX2[i]][cY1[i]][cZ2[i]]++;
        imos[cX2[i]][cY2[i]][cZ1[i]]++;
        imos[cX2[i]][cY2[i]][cZ2[i]]--;
    }

    rep(x, sz(Xs)){
        rep(y, sz(Ys)){
            rep1(z, sz(Zs) - 1){
                imos[x][y][z] += imos[x][y][z - 1];
            }
        }
    }

    rep(z, sz(Zs)){
        rep(y, sz(Ys)){
            rep1(x, sz(Xs) - 1){
                imos[x][y][z] += imos[x - 1][y][z];
            }
        }
    }

    rep(x, sz(Xs)){
        rep(z, sz(Zs)){
            rep1(y, sz(Ys) - 1){
                imos[x][y][z] += imos[x][y - 1][z];
            }
        }
    }

    ll ans = 0;
    rep(x, sz(Xs) - 1){
        rep(y, sz(Ys) - 1){
            rep(z, sz(Zs) - 1){
                if(imos[x][y][z] >= K){
                    ans += (Xs[x + 1] - Xs[x]) * (Ys[y + 1] - Ys[y]) * (Zs[z + 1] - Zs[z]);
                }
            }
        }
    }
    // for(auto xs : Xs){
    //     show(xs);
    // }
    // for(auto ys : Ys){
    //     show(ys);
    // }
    // for(auto zs : Zs){
    //     show(zs);
    // }

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