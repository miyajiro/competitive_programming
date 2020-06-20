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
typedef pair<double,double> DP;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;
ll N;
string s;
LP p[100];
LP p2[100];
ll pows[10];

int main()
{
    pows[0]=1;
    rep1(i,9){
        pows[i] = pows[i-1]*26;
    }
    cin>>N;
    rep(i,N){
        cin>>s>>p[i].sc;
        p[i].sc = -p[i].sc;
        rep(j, s.size()){
            p[i].fr += (s[j]-'a')*pows[9-j];
        }
        p2[i] = p[i];
    }
    sort(p2, p2+N);
    rep(i, N){
        ll res = 0;
        rep(j, N){
            if(p2[i] == p[j]) res = j;
        }
        cout<<res+1<<endl;
    }
}
