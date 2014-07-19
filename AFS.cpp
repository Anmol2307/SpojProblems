/******************************************************************
***   Problem No    : Spoj 13753                                ***
***   Problem Name  : Amazing Prime Sequence                    ***
***   Type          : Number theory , prime                     ***
***   Author        : Shipu Ahamed (Psycho Timekiller)          ***
***   E-mail        : shipuahamed01@gmail.com                   ***
***   University    : BUBT,Dept. of CSE                         ***
***   Team          : BUBT_Psycho                               ***
***   Facebook      : http://www.facebook.com/DeesheharaShipu   ***
******************************************************************/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pi 2*acos(0.0)
#define all(v) v.begin(),v.end()
 
//For Define
#define for0(i,n) for(__typeof(n) i=0;i<(n);i++)
#define for1(i,n) for(__typeof(n) i=1;i<=(n);i++)
#define rfor0(i,n) for(__typeof(n) i=(n);i>=0;i--)
#define rfor1(i,n) for(__typeof(n) i=(n);i>=1;i--)
#define For(i,a,b) for(__typeof(b) i=a;i<=b;i++)
 
//input
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define sf(t) scanf("%f",&t)
#define sdb(t) scanf("%lf",&t)
#define schar(c) scanf("%c",&c)
#define sstring(s) scanf("%s",s)
#define ssi(a,b) scanf("%d%d",&a,&b)
#define ssl(a,b) scanf("%lld%lld",&a,&b)
 
//Output
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PF(a) printf("%f\n",a)
#define PDB(a) printf("%lf\n",a)
#define PN(a) printf("%d ",a)
#define PLN(a) printf("%lld ",a)
#define PFN(a) printf("%f ",a)
#define PDBN(a) printf("%lf ",a)
 
#define CP(a) cout<<a<<endl
#define CPN(a) cout<<a<<" "
 
//Test Case & New line
#define Case(no) printf("Case %d: ",++no)
#define nl puts("")
 
//Debug
#define db(x) cout << #x << " -> " << (x) << endl;
#define db_sarr(i,a) cout<<#a<<"["<<i<<"] -> "<<a[i]<<" "<<endl;
#define db_arr(a,start,end) for(ll i=start;i<=end;i++) cout<<#a<<"["<<i<<"] -> "<<a[i]<<" "<<endl;
#define db_mat(mat,row,col) for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cout<<mat[i][j]<<" ";cerr<<endl;}
#define db_st(a,b,start,end) for(ll i=start;i<=end;i++) cout<<#a<<"["<<i<<"]."<<#b<<" -> "<<a[i].b<<" "<<endl;
 
#define ff first
#define se second
#define pb push_back
#define ppb pop_back
#define mkp(a,b) make_pair(a,b)
#define ST(v) sort(all(v))
#define sz(x) (int)x.size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)                         //count one
#define parity(i)   __builtin_parity(i)       //evenparity 0 and odd parity 1
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define un(v) ST(v), (v).erase(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
 
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  vector<string> vs;
typedef  pair<int,int> pii;
typedef  vector<pii> vpii;
typedef  set<int> si;
typedef  set<string> ss;
typedef  map<int,int> mii;
typedef  map<string,int> msi;
 
////============ CONSTANT ===============////
#define MAXLL 9223372036854775807
#define MINLL 9223372036854775808
#define MAXL  2147483647
#define MINL  2147483648
#define mx7   1000007
#define mx6   1000006
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mx    (100010)
#define mod   1000000007
////=====================================////
 
ll pd[mx7+10],a[mx7+10];
bool prime[mx7+10];
 
void sieve(){
        for (ll i = 2; i <=mx7; i+= 2)
           prime[i]=1, pd[i] = 2;
 
        for (ll i = 3; i <=mx7; i += 2){
                if (!prime[i]){
                    pd[i] = i;
                    for (ll j=i; (j*i) <=mx7; j += 2)
                    {
                        prime[j*i] = 1;
                        if(!pd[j*i])
                        pd[j*i] = i;
                    }
                }
        }
}
 
void solve()
{
    a[0]=0;
    a[1]=0;
    for(int i=2;i<=mx7;i++)
    {
        a[i]=a[i-1]+pd[i];
    }
}
 
 
int main()
{
    sieve();
    solve();
    int t;
    si(t);
    while(t--)
    {
        int n;
        si(n);
        PL(a[n]);
 
    }
    return 0;
}