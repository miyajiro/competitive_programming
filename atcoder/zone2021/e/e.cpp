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

using T = pair<ll, pair<ll, ll>>;

ll H, W;
ll A[500][500], B[500][500];
priority_queue<T, vector<T>, greater<T>> pq;
ll dist[500][500];
const ll INF = 0xfffffffffffffff;

int main()
{
    cin >> H >> W;
    rep(h, H){
        rep(w, W - 1){
            cin >> A[h][w];
        }
    }

    rep(h, H - 1){
        rep(w, W){
            cin >> B[h][w];
        }
    }

    rep(h, H){
        rep(w, W){
            dist[h][w] = INF;
        }
    }
    dist[0][0] = 0;
    pq.push(T(0, LP(0, 0)));

    while(!pq.empty()){
        T t = pq.top();
        pq.pop();

        int D = t.fr;
        int y = t.sc.fr;
        int x = t.sc.sc;
        if(D > dist[y][x]){
            continue;
        }

        if(x < W - 1 && dist[y][x+1] > dist[y][x] + A[y][x]){
            dist[y][x+1] = dist[y][x] + A[y][x];
            pq.push(T(dist[y][x+1], LP(y, x+1)));
        }

        if(x > 0 && dist[y][x-1] > dist[y][x] + A[y][x-1]){
            dist[y][x-1] = dist[y][x] + A[y][x-1];
            pq.push(T(dist[y][x-1], LP(y, x-1)));
        }

        if(y < H - 1 && dist[y+1][x] > dist[y][x] + B[y][x]){
            dist[y+1][x] = dist[y][x] + B[y][x];
            pq.push(T(dist[y+1][x], LP(y+1, x)));
        }

        rep(ny, y){
            if(dist[ny][x] > dist[y][x] + (y - ny) + 1){
                dist[ny][x] = dist[y][x] + (y - ny) + 1;
                pq.push(T(dist[ny][x], LP(ny, x)));
            }
        }
    }

    cout << dist[H-1][W-1] << endl;

    return 0;
}