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
#define show(x) cout << #x << " = " << x << endl;
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

int doctorNum, bookNum;
vi book2NumOfDoctor;
vvi book2DoctorArray;
vvi doctor2BookArray;

vi book2Rank;
vi doctor2Rank;
PQ(P) doctorRankAndDoctorPQ;

void solve()
{
    cin >> doctorNum >> bookNum;
    book2NumOfDoctor = vi(bookNum);
    book2DoctorArray = vvi(bookNum);

    doctor2BookArray = vvi(doctorNum);

    book2Rank = vi(bookNum, -1);
    doctor2Rank = vi(doctorNum, -1);

    rep(bookId, bookNum){
        int numOfDoctor;
        cin >> numOfDoctor;
        book2NumOfDoctor.pb(numOfDoctor);
        rep(doctorId, numOfDoctor){
            int doctor;
            cin >> doctor;
            doctor--;
            book2DoctorArray[bookId].pb(doctor);
            doctor2BookArray[doctor].pb(bookId);
        }
    }

    doctor2Rank[0] = 0;
    doctorRankAndDoctorPQ.push(P(0, 0));
    while(!doctorRankAndDoctorPQ.empty()){
        P doctorRankAndDoctor = doctorRankAndDoctorPQ.top();
        doctorRankAndDoctorPQ.pop();

        int doctorRank = doctorRankAndDoctor.fr;
        int doctorId = doctorRankAndDoctor.sc;
        // show(doctorRank);
        // show(doctorId);

        for(auto bookId : doctor2BookArray[doctorId]){
            if(book2Rank[bookId] != -1){
                continue;
            }

            int bookRank = doctorRank;
            book2Rank[bookId] = bookRank;
            for(auto coDoctor : book2DoctorArray[bookId]){
                if(doctor2Rank[coDoctor] != -1){
                    continue;
                }
                int coDoctorRank = bookRank + 1;
                doctor2Rank[coDoctor] = coDoctorRank;
                doctorRankAndDoctorPQ.push(P(coDoctorRank, coDoctor));
            }
        }
    }

    rep(doctorId, doctorNum){
        cout << doctor2Rank[doctorId] << "\n";
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}