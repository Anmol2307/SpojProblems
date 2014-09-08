#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

int matrix[1025][1025];
int n;

int read(int x, int y){
  int y1,sum=0;
  while (x > 0) {
    y1 = y;
    while (y1 > 0) {
      sum += matrix[x][y1];
      y1 -= (y1 & -y1);  
    }
    x -= (x & -x);
  }
  return sum;
}

void update(int x , int y , int val){
  int y1;
  while (x <= n){
    y1 = y;
    while (y1 <= n){
      matrix[x][y1] += val;
      y1 += (y1 & -y1); 
    }
    x += (x & -x); 
  }
}

int main () {
  int t;
  inp(t);

  while (t--) {
    memset(matrix,0,sizeof(matrix));
    inp(n);
    char ch[5];
    while (scanf("%s",ch) == 1) {
      if (!strcmp(ch,"END")) break;
      if (!strcmp(ch,"SET")) {
        int x1, y1, val;
        inp(x1); inp(y1); inp(val);
        int val1 = read(x1+1,y1+1);
        int val2 = read(x1+1,y1);
        int val3 = read(x1,y1);
        int val4 = read(x1,y1+1);
        update(x1+1,y1+1,val -(val1-val2-val4+val3));
      }
      if (!strcmp(ch,"SUM")) {
        int x1, y1, x2, y2;
        inp(x1);inp(y1);inp(x2);inp(y2);
        int val1= read(x2+1,y2+1);
        int val2= read(x2+1,y1);
        int val3= read(x1,y1);
        int val4= read(x1,y2+1);
        printf("%d\n",val1 - val2 - val4 + val3);
      }
    }
  }
}