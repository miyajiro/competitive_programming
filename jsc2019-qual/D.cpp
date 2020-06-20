#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++i)
#define rrep(i, n) for (int(i) = (n)-1; (i) >= 0; --i)
#define rep1(i, n) for (int(i) = 1; (i) <= (n); ++i)
#define rrep1(i, n) for (int(i) = (n); (i) >= 1; --i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> LP;
typedef double db;
using namespace std;

set<ll> s[501];
ll A[501][501];
ll pos;

void calc(ll n)
{
    if (n == 2)
    {
        A[1][2] = A[2][1] = 1;
        s[1].insert(1);
        s[2].insert(2);
        pos = 1;
        return;
    }
    calc(n - 1);
    rep(i, n)
    {
        A[i][N - 1] = ;
    }
}

int main()
{
    ll N;
    calc(N);
    rep1(i, N - 1)
    {
        for (int j = i + 1; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << A[i][N] << endl;
    }
}
