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

using namespace std;
#define mm 1000000


///////////////////////////////////////////////////////////////////////////////////////////
// vector <int> prime;
bool check[mm];
int divcount[mm];
bool ncheck[mm];


void divisors () {
  int total = 0;

  for (int i = 2; i < mm; i++) {
      int count = divcount[i];
      int flag = true;
      if (count > 3) {
        for  (int j = 2; j <= sqrt(i); j++) {
            if (i%j == 0 ){
              if ( count%divcount[i/j] == 0 && count%divcount[j] == 0) {
                continue;
              }
              else {
                flag = false;
                break;
              }
            }
        }
        if (flag) {
          total++;
          if (total%108 == 0) printf("%d\n",i);
          // cout <<"YES " << i << " " << count << endl;
        }
      }
      
  }

}
void sieve(){
        
        for (int i = 2; i <mm; i++){
           divcount[i] = 2;
        }
        
        for (int i = 2; i <sqrt(mm); i++){
                // if (!check[i]){
                    check[i*i] = 1;
                    divcount[i*i] +=1;
                    for (int j=i+1; (j*i) <mm; j++)
                    {
                        check[j*i] = 1;
                        divcount[j*i] +=2;
                    }

                // }
        }
        for (int i = 2; i <sqrt(mm); i++){
               
                    int count = divcount[i];
                    
                    if (count <= 3) {
                      ncheck[i] = 1;
                    }
                    for (int j=i; (j*i) <mm; j++)
                    {
                        // check[j*i] = 1;
                        int dum = divcount[j*i];
                        if (dum <= 3 || dum%count != 0 || dum%divcount[j] != 0) {
                          ncheck[j*i] = 1;
                        }
                    }
        }
        int total = 0;

        for (int  i = 2; i < mm; i++) {
          if (check[i] && !ncheck[i]) {
            total++;
            if (total%108 == 0) cout << i << endl;
            
          }
        }
}


int main () {
    sieve();
    // divisors();
    return 0;
} 