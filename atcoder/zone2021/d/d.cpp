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

string S;
string ans;
deque<char> dq;

int main()
{
    cin >> S;
    int rCnt = 0;
    rep(i, S.size()){
        if(S[i] == 'R'){
            rCnt++;
        }
    }

    bool isRev = (rCnt % 2 == 1);

    bool addRight = true;

    rep(i, S.size()){
        if(S[i] == 'R'){
            addRight = !addRight;
            continue;
        }

        if(addRight){
            if(dq.size() > 0 && dq.back() == S[i]){
                dq.pop_back();
                continue;
            }

            dq.push_back(S[i]);
        } else {
            if(dq.size() > 0 && dq.front() == S[i]){
                dq.pop_front();
                continue;
            }

            dq.push_front(S[i]);
        }
    }

    while(dq.size() > 0){
        if(isRev){
            ans += dq.back();
            dq.pop_back();
        } else {
            ans += dq.front();
            dq.pop_front();
        }

    }

    cout << ans << endl;

    return 0;
}