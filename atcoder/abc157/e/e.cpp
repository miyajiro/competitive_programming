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

int N, Q;
vi Q1, Q2;
v(string) Q3;
string S;
v(fenwick_tree<int>) ftArray;

int main()
{
    cin >> N >> S >> Q;
    rep(_, 26)
    {
        ftArray.push_back(fenwick_tree<int>(N));
    }

    rep(i, N)
    {
        ftArray[S[i] - 'a'].add(i, 1);
    }

    rep(i, Q)
    {
        int q1, q2;
        string q3;
        cin >> q1 >> q2 >> q3;

        if (q1 == 1)
        {
            int id = q2 - 1;
            char c = q3[0];
            ftArray[S[id] - 'a'].add(id, -1);
            S[id] = c;
            ftArray[S[id] - 'a'].add(id, 1);
        }
        else
        {
            int l = q2 - 1;
            int r = stoi(q3);
            int ans = 0;

            rep(a, 26)
            {
                if (ftArray[a].sum(l, r) > 0)
                    ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}