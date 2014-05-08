#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

static int L[6101][6101];
	
char* reverse (char* str) {
	int sz = strlen(str);
	string newstr(str);
	for (int i = 0; i < sz/2; i++) {
		char x = newstr[i];
		newstr[i] = newstr[sz-i-1];
		newstr[sz-i-1] = x;
	}
	char *  strnew  = new char[newstr.size()+1];
	strcpy(strnew, newstr.c_str());
	return strnew;
	//delete strnew;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(char* X,char* Y, int m, int n )
{
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   // for (int i = 0; i < m; i++) {
   // 	cout << X[i] << " ";
   // }
   // cout << endl;

   // for (int i = 0; i < n; i++) {
   // 	cout << Y[i] << " ";
   // }
   // cout << endl;
   
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
  

int main () {

	int t;
	cin >>t;
	while (t--) {
		char* str;
		cin >> str;
		
		char *revstr = reverse(str);
		
		int m = strlen(str);
		int n = strlen(revstr);
		
		int num = lcs(str,revstr,m,n);
		
		cout << m - num << endl;
		delete str;
		delete revstr;
	}
}