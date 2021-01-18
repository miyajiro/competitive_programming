#include <bits/stdc++.h>
#define fr first
#define sc second
#define rep(i, n) for (long long i = 0LL; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i >= 1; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (long long)(x).size()
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
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;

vl L, R, X;
vl T, ans;
ll N, Q;
priority_queue<LP, vector<LP>, greater<LP>> koji_pq; // (工事のx, 工事のID)
vector<LP> eventTimeAndIndexArray;                   // イベント(工事開始 or 人の出発)時刻, index

int main()
{
    cin >> N >> Q;
    rep(i, N)
    {
        L.pb(0LL);
        R.pb(0LL);
        X.pb(0LL);
        cin >> L[i] >> R[i] >> X[i];
        eventTimeAndIndexArray.pb(LP((L[i] - X[i]) * 2LL - 1LL, i));
    }
    rep(i, Q)
    {
        ans.pb(0);
        T.pb(0);
        cin >> T[i];
        eventTimeAndIndexArray.pb(LP(T[i] * 2LL, N + i));
    }
    sort(rng(eventTimeAndIndexArray));

    rep(i, eventTimeAndIndexArray.size())
    {
        LP eventTimeAndIndex = eventTimeAndIndexArray[i];
        ll index = eventTimeAndIndex.second;
        if (index < N)
        { // 工事始まり
            koji_pq.push(LP(X[index], index));
        }
        else
        { // 人歩き始め
            index -= N;
            while (true)
            {
                if (koji_pq.empty()) // 工事場所は存在しないので-1
                {
                    ans[index] = -1;
                    break;
                }
                ll koji_id = koji_pq.top().second;
                if (R[koji_id] - X[koji_id] <= T[index])
                { // 工事終了なのでcontinue
                    koji_pq.pop();
                    continue;
                }

                // 最小のxが工事中の場合
                ans[index] = X[koji_id];
                break;
            }
        }
    }

    rep(i, Q)
    {
        cout << ans[i] << endl;
    }

    return 0;
}