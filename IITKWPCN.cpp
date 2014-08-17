#include <cstdio>

using namespace std;

int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    int w,b;
    scanf("%d %d",&w,&b);
    if(b%2==0)
      printf("0.000000\n");
    else
      printf("1.000000\n");
  }
  return 0;
}