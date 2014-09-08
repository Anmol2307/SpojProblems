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
struct query {
  int x1, y1, x2, y2, d;
  query(int a, int b, int c, int e, int f) {
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = e;
    d = f;
  }
};

bool check (int x, int y, query c) {
  if (x >= c.x1 && x <= c.x2 && y >= c.y1 && y <= c.y2) return true;
  return false;
}

char find (char c, int dir) {
  if (dir == 0) return c;
  else if (dir == 1) {
    switch(c)
    {
      case 'N': return 'E'; 
      case 'E': return 'S';
      case 'S': return 'W';
      case 'W': return 'N';  
    }
  }
  else if (dir == 2) {
    switch(c)
    {
      case 'N': return 'S'; 
      case 'E': return 'W';
      case 'S': return 'N';
      case 'W': return 'E';  
    }
  }
  else if (dir == 3) {
    switch(c)
    {
      case 'N': return 'W'; 
      case 'E': return 'N';
      case 'S': return 'E';
      case 'W': return 'S';  
    }
  }
}

int main () {
  int m, n;
  inp(m); inp(n);
  vector <char*> mat;
  for (int i = 0; i < m; i++) {
    char* in = new char[n];
    scanf("%s",in);
    mat.push_back(in);
  }

  int c;
  inp(c);
  vector <query> command;
  for (int i = 0; i < c; i++) {
    char ch;
    scanf("%c",&ch);

    if (ch == 'C') {
      int x1, y1, x2, y2, d;
      inp(x1); inp(y1); inp(x2); inp(y2); inp(d);

      query q(x1,y1,x2,y2,d);
      command.push_back(q);
    }
    else if (ch == 'D') {
      int x, y, dir = 0;
      inp(x); inp(y);

      for (int j = 0; j < command.size(); j++) {
        if (check(x,y,command[j])) {
          if (command[j].d == 1) dir -= 1;
          else dir += 1;
        }
      }
      dir += 4*command.size();
      dir %= 4;
      char ans = find(mat[x-1][y-1],dir);
      printf("%c\n",ans);
    }

  }

}