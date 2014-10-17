#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector <int> graph[N];
int visited[N];

int main () {
  int t;
  scanf("%d", &t);

  while (t--) {
    memset(visited,0,sizeof(visited));
    
    

    int n, e;
    scanf("%d %d", &n, &e);
    
    for (int i = 0; i < n; i++) {
      graph[i].clear();
    }

    for (int i = 0; i < e; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {

      if (!visited[i]) {
        ans++;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
          int tp = q.front();
          q.pop();

          for (int i = 0; i < graph[tp].size(); i++) {
            if (!visited[graph[tp][i]]) {
              q.push(graph[tp][i]);
              visited[graph[tp][i]] = 1;
            }
          }
        }

        visited[i] = 1;
      }
    }
    printf("%d\n",ans);
  }
}