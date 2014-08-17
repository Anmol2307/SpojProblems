// Connected components and ad-hoc

#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;

const int MAX = 100005;
 
vector <int> A,B[MAX],C,D;
int visited[MAX];
int n,m;
 
void DFS(int u) {
  visited[u]=1;
  C.push_back(u);
  for(int i=0; i<B[u].size(); i++) {
    int current=B[u][i];
    if(visited[current]==0)
      DFS(current); 
  }
}
 
int main() {
  int cases;scanf("%d",&cases);
  while(cases--) {
    A.clear();
    scanf("%d %d",&n,&m);
     
    for(int i=0; i<=n; i++)
      visited[i]=0;
     
    for(int i=0; i<n; i++) {
      int val;scanf("%d",&val);
      A.push_back(val);
    }
     
    for(int i=0; i<MAX; i++)
      B[i].clear();
     
    for(int i=0; i<m; i++) {
      int a,b;
      scanf("%d %d",&a,&b);
      B[a].push_back(b);
      B[b].push_back(a);
    }
     
    for(int i=1; i<=n; i++) {
      C.clear();D.clear();
      if(visited[i]==0) {
        DFS(i); 
        for(int j=0; j<C.size(); j++) {
          D.push_back(A[C[j]-1]);
        }
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        for(int j=0; j<C.size(); j++) {
          A[C[j]-1] = D[j];
        }
      }
    }
     
    for(int i=0; i<A.size(); i++)
      printf("%d ",A[i]);
    printf("\n");
     
  }
  return 0;
}