#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

ll N, K;
ll A[2000];
ll th[2000];
ll th_right[2000];
ll ans=0;
ll mod = 1000000007;

int main()
{
    cin>>N>>K;
    rep(i, N) cin>>A[i];
    rep(i, N){
        rep(j, N){
            if(A[i]>A[j]){
                th[i]++;
                if(i<j) th_right[i]++;
            }
        }
    }
    rep(i, N){
        // cout<<th[i]<<" "<<th_right[i]<<endl;
        ans += (th_right[i] * K) % mod;
        ans %= mod;
        ans += (th[i] * (((K * (K-1)) / 2) % mod)) % mod;
        ans %= mod;
    }
    cout<<ans<<endl;
}
