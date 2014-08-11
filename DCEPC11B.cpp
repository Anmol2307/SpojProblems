//Based on Wilson's Algorithm and Fermat's Little Theorm


#include<stdio.h>
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>



#define true 1
#define false 0
#define INF 100000

#define MAX 100000
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)



typedef long long ll;

using namespace std;



ll fastexp(ll a,ll b,ll mod){
    ll res;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    res = fastexp(a,b/2,mod)%mod;
    if(b%2==0)
        return (res*res)%mod;
    else
        return ( ( (res*res)%mod)*a)%mod;
}


int main(){

ll t,n,p,res,i;

cin>>t;

while(t--){
    cin>>n>>p;

    if(n >= p){
        cout<<"0"<<endl;continue;
    }
    if(n==1){
        cout<<"1"<<endl;
        continue;
    }
    if(n==p-1){
        cout<<p-1<<endl;
        continue;
    }
        res = 1;

    for(i=n+1;i <= p-2 ;i++)
        res = (res*i)%p;


    res = fastexp(res,p-2,p);

    cout<<res<<endl;

}




return 0;
}   