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

using MOD = modint;

int p, a, b;
int rankA, rankB;

int main()
{
    cin >> p >> a >> b;
    MOD::set_mod(p);
    MOD a1 = a;
    MOD b1 = b;
    rankA = 1;
    while(a1.val() != 1){
        a1 *= a;
        rankA++;
    }
    while(b1.val() != 1){
        b1 *= b;
        rankB++;
    }
    if(rankA < rankB){
        swap(rankA, rankB);
        swap(a, b);
    }
    // show(a);
    // show(rankA);
    // show(b);
    // show(rankB);

    if(rankA == p - 2){
        MOD v = 1;
        puts("Yes");
        cout << 1;
        rep(i, p - 1){
            v *= a;
            cout << " " << v.val();
        }
        newline;
        return 0;
    }

    // if(rankA * 2 == p - 1){
    //     MOD v = 1;
    //     puts("Yes");
    //     cout << 1;
    //     rep(i, rankA - 1){
    //         v *= a;
    //         cout << " " << v.val();
    //     }
    //     v *= b;
    //     cout << " " << v.val();
    //     rep(i, rankA - 1){
    //         v /= a;
    //         cout << " " << v.val();
    //     }
    //     cout << " " << 1;
    //     newline;
    //     return 0;
    // }

    if(p - 1 - rankA * 2 <= 2 * rankB){
        MOD v = 1;
        puts("Yes");
        cout << 1;
        rep(i, rankA - 1){
            v *= a;
            cout << " " << v.val();
        }
        int bnum = 1 + (p - 1 - rankA * 2) / 2;
        rep(_, bnum){
        v *= b;
        cout << " " << v.val();}
        rep(i, rankA - 1){
            v /= a;
            cout << " " << v.val();
        }
        rep(_, bnum){
        v /= b;
        cout << " " << v.val();}
        newline;
        return 0;
    }
    puts("No");

    return 0;
}