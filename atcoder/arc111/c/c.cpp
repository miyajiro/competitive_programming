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

ll N;
vl a, b;
v(LP) weightAndIndex;
vl parcelIndexSorted;
vl parcel2People;
vl people2Parcel;
v(LP) op;

int main()
{
    cin >> N;
    rep(i, N){
        ll _a;
        cin >> _a;

        a.pb(_a);
        people2Parcel.pb(0);
        parcel2People.pb(0);
    }

    rep(i, N){
        ll _b;
        cin >> _b;
        b.pb(_b);
        people2Parcel.pb(0);
        parcel2People.pb(0);
        weightAndIndex.pb(LP(_b, i));
    }

    sort(rng(weightAndIndex), greater<LP>());
    for(auto lp : weightAndIndex){
        parcelIndexSorted.pb(lp.sc);
    }

    rep(i, N){
        ll pi;
        cin >> pi;
        pi--;
        people2Parcel[i] = pi;
        parcel2People[pi] = i;

        if(a[i] <= b[pi] && i != pi){
            puts("-1");
            return 0;
        }
    }

    for(auto pi : parcelIndexSorted){
        if(parcel2People[pi] == pi){
            continue;
        }

        ll people1 = pi;
        ll people2 = parcel2People[pi];
        ll parcel1 = people2Parcel[pi];
        ll parcel2 = pi;

        op.pb(LP(people1 + 1, people2 + 1));

        parcel2People[parcel1] = people2;
        parcel2People[parcel2] = people1;
        people2Parcel[people1] = parcel2;
        people2Parcel[people2] = parcel1;
    }

    cout << op.size() << endl;

    for(auto _op : op){
        cout << _op.fr << " " << _op.sc << endl;
    }

    return 0;
}