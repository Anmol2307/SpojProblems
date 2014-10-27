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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 100005

char str1[N], str2[N];
char* ans;
int k, l;
void find (int i, int j) {
  if (i == strlen(str1)) {
    int sz = strlen(str2);
    for (int x = 0; x < sz; x++) {
      ans[k++] = str2[x];
    }
  }
  else if (str1[i] < str2[j]) {
    ans[k++] = str1[i];
    find(i+1,j);
  }
  else if (str1[i] == str2[j]) {
    char ans2[2*N];
    strcpy(ans2,ans);
    l = k;

    ans[k++] = str1[i];
    find(i+1,j);


    int sz = strlen(str2);
    for (int x = 0; x < sz; x++) {
      ans2[l++] = str2[x];
    }

    sz = strlen(str1);
    for (int x = i; x < sz; x++) {
      ans2[l++] = str1[x];
    }
    if (strcmp(ans,ans2) > 0) strcpy(ans,ans2);
  }
  else {
    int sz = strlen(str2);
    for (int x = 0; x < sz; x++) {
      ans[k++] = str2[x];
    }

    sz = strlen(str1);
    for (int x = i; x < sz; x++) {
      ans[k++] = str1[x];
    }
  }
}


int main () {
    while (scanf("%s", str1) == 1 && scanf("%s", str2) == 1) {
      ans = new char[2*N];
      k = 0; l = 0;
      find(0,0);  
      printf("%s\n",ans);
    }
}
