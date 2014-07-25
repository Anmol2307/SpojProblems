#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

map<char,int> memo;

int main() {
   int nT; cin >> nT;
   string str;
   int k = 1;
   while (nT-- && cin >> str) {
      memo.clear();
      int next = 0;
      memo[str[0]] = 1;
      for (int i = 1; i < str.size(); i++) {
         if (memo.count(str[i]) == 0) {
            memo[str[i]] = next;
            next++;
            if (next == 1) next++;
         }
      }
      long long val = 0;
      int base = next == 0 ? 2 : next;
      for (int i = 0; i < str.size(); i++) {
         val = val * base + memo[str[i]];
      }
      cout << "Case #" << k << ": " << val << "\n";
      k++;
   }
   return 0;
}