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

ll mod = 1000000007;
string s;
ll N;
ll A[200000];
ll a[200000];
bool is_right[200000];
ll ans;
ll kaijo[200001];
bool flag = false;

bool ok(){
    ll right = 0;
    ll right_cnt = 0;
    rep(i, 2*N){
        if(flag) A[i] = 1-A[i];
        if(i == 0 || A[i] != A[i-1]){
            right += 1;
            right_cnt += 1;
            flag = !flag;
            is_right[i] = true;
            if(right_cnt>N) return false;
        }
        else{
            right -= 1;
            is_right[i] = false;
            if(right<0){
                return false;
            }
        }
        A[i] = 1-A[i];
    }
    if(A[2*N-1] == 0) return true;
    else return false;
}

int main()
{
    cin>>N;
    cin>>s;
    rep(i, 2*N){
        if(s[i] == 'W'){
            A[i] = 0;
        }
        else A[i] = 1;
        if(N % 2 == 1) A[i] = 1-A[i];
    }
    kaijo[0] = 1;
    rep1(i, 2*N){
        kaijo[i] = (kaijo[i-1] * i) % mod;
    }
    ans = 0;
    if(ok()){
        ans = 1;
        ll right_num = 0;
        rep(i, 2*N){
            if(is_right[i]) right_num+=1;
            else{
                ans = (ans * right_num) % mod;
                right_num -= 1;
            }
        }
        ans *= kaijo[N];
        ans %= mod;
    }
    cout<<ans%mod<<endl;
}