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
using E = pair<ll, LP>; // pair<座標, <モンスター0蓄積減1, 体力/蓄積ダメージ>>

ll N;
ll D;
ll A;
vl X;
vl H;

ll ans;

priority_queue<E, vector<E> ,greater<E>> pq;

int main()
{
    cin >> N >> D >> A;
    D *= 2;
    rep(i, N){
        ll x, h;
        cin >> x >> h;
        X.pb(x);
        H.pb(h);
        pq.push(E(x, LP(0, h)));
    }

    ll damage = 0;
    while(!pq.empty()){
        E e = pq.top();
        ll zahyo = e.fr;
        pq.pop();
        if(e.sc.fr == 0){ // モンスターの場合
            ll hp = e.sc.sc;
            hp -= damage;
            if(hp <= 0){
                continue;
            }

            ll kaisu = ((hp - 1) / A) + 1;
            ans += kaisu;
            damage += kaisu * A;
            pq.push(E(zahyo + D, LP(1, kaisu * A)));
        } else { // 蓄積ダメージを取り消す場合
            damage -= e.sc.sc;
        }
    }

    cout << ans << endl;
    return 0;
}