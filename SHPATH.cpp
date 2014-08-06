#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>
#include <iterator>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}


string ip(string &i)
{
    i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}
///////////////////////////////////////////////////////////////////////////////////////////
typedef pair<int,int> ii;
typedef pair<string,int> psi;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vii> vvii;

#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 


// vvii G(10001);
// distance from start vertex to each vertex

  // int dijkstraPQ (int source,int destination) {
  //     vi D(10001, 200001);
  //     priority_queue<ii,vector<ii>, greater<ii> > Q; 
  //     // priority_queue with reverse comparison operator, 
  //     // so top() will return the least distance
  //     // initialize the start vertex, suppose it’s zero
  //     D[source] = 0;
  //     Q.push(ii(source,0));

  //     // iterate while queue is not empty
  //     while(!Q.empty()) {

  //           // fetch the nearest element
  //           ii top = Q.top();
  //           Q.pop();
                        
  //           // v is vertex index, d is the distance
  //           int v = top.first, d = top.second;
  //           // printf("pt1 %d %d\n",v,d);
  //           // this check is very important
  //           // we analyze each vertex only once
  //           // the other occurrences of it on queue (added earlier) 
  //           // will have greater distance
  //           if(d <= D[v]) {
  //                 // iterate through all outcoming edges from v
  //                 tr(G[v], it) {
  //                       int v2 = it->first, cost = it->second;
  //                       // printf("pt2 %d %d\n",v2,cost);
  //                       if(D[v2] > D[v] + cost) {
  //                             // update distance if possible
  //                             D[v2] = D[v] + cost;
  //                             // add the vertex to queue
  //                             Q.push(ii(v2, D[v2]));

  //                       }
  //                 }
  //           }
  //           // else {
  //           //   printf("HERE %d %d %d\n",v,d,D[v]);
  //           // }
  //     }
  //     return D[destination];
  //   }

int main () {
  
  int t;
  // scanf("%d",&t);
  inp(t);

  while (t--) {
    int n;
    inp(n);
    // scanf("%d",&n);
    char name[20];
    vvii G(n+1);
    map<string,int> nodes;
    for (int i = 1; i <= n; i++) {
      // scanf("%s",name);
      // ip(name);
      scanf("%s",name);
      nodes.insert(psi(name,i));
      // printf("%d\n",nodes[name]);
      int x; 
      inp(x);
      // scanf("%d",&x);
      for (int j = 0; j < x; j++) {
        int neigh,cost;
        inp(neigh); inp(cost);
        // scanf("%d %d",&neigh,&cost);
        ii p(neigh,cost);
        G[i].push_back(p);
      }
      // printf("%s\n",name);
    }
    int paths;
    inp(paths);
    // scanf("%d",&paths);
    // printf("HERE %d\n",paths);
    // string sr, de;
    for (int i = 0; i < paths; i++) { 
      // scanf("%s %s",source, dest);
      scanf("%s",name);
      map< string, int > :: iterator it;
      // printf("%d %d\n",nodes[source],nodes[dest]);
      // int ans = dijkstraPQ(nodes[source],nodes[dest]);
      it = nodes.find(name);
      // start = (*it).second;
      int source = (*it).second;
      scanf("%s",name);
      it = nodes.find(name);
      int dest = (*it).second;
      vi D(n+1, 200001);
      vi Vis(n+1,0);
      priority_queue<ii,vector<ii>, greater<ii> > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[source] = 0;
      Q.push(ii(source,0));

      // iterate while queue is not empty
      while(!Q.empty()) {

            // fetch the nearest element
            ii top = Q.top();
            Q.pop();

            // v is vertex index, d is the distance
            int v = top.first, d = top.second;
            if (Vis[v]) continue;
            
            // printf("pt1 %d %d\n",v,d);
            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            // if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  tr(G[v], it) {
                        int v2 = it->first, cost = it->second;
                        // printf("pt2 %d %d\n",v2,cost);
                        if(!Vis[v2] && D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(ii(v2, D[v2]));

                        }
                  }
                  Vis[v] = 1;
                  if (v == dest) break;
            // }
            // else {
            //   printf("HERE %d %d %d\n",v,d,D[v]);
            // }
      }

      printf("%d\n",D[dest]);
    }
    // for(int i=1; i<=n; i++) G[i].clear();
    // nodes.clear();
  }

}