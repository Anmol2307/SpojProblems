#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

vector<string> tokenize(string inp) {
  vector<string> ans;
  int start, end;
  for (int i = 0; i < inp.size();) {
    if (inp[i] != '+' && inp[i] != '-' && inp[i] != '*' && inp[i] != '/' && inp[i] != '%' && inp[i] != '(' && inp[i] != ')') {
      start = i; end = i;
      i++;
      while (inp[i] != '+' && inp[i] != '-' && inp[i] != '*' && inp[i] != '/' && inp[i] != '%' && inp[i] != '(' && inp[i] != ')') {
        end++;i++;
      }
      string tmp = inp.substr(start,end-start+1);
      ans.push_back(tmp);
    }
    else {
      string s(1,inp[i]);
      ans.push_back(s);
      i++;
    }
  }
  return ans;
}

ll stringtoint(string str) {
  stringstream s;
  s << str;
  ll a;
  s >> a;
  return a;
}

ll appply (string op, ll oper2, ll oper1) {
  if (op == "+")
    return (oper1+oper2);
  if (op == "-")
    return (oper1-oper2);
  if (op == "*")
    return (oper1*oper2);
  if (op == "/")
    return oper1/oper2;
  if (op == "%")
    return oper1%oper2;
}

bool hasPrecedence (string op1, string op2) {
  if (op2 == "(" || op2 == ")") 
    return false;
  return true;
}


int evaluate (vector<string> tokens) {
  stack<ll> values;
  stack<string> ops;

  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "%" && tokens[i] != "(" && tokens[i] != ")") {
      values.push(stringtoint(tokens[i]));
    }
    else if (tokens[i] == "(") {
      ops.push(tokens[i]);
    }
    else if (tokens[i] == ")") {
      while (ops.top() != "(") {
        ll val1 = values.top();
        values.pop();
        ll val2 = values.top();
        values.pop();
        ll val = appply(ops.top(),val1,val2);
        ops.pop();
        values.push(val);
      }
      ops.pop();
    }
    else if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "%") {
      while(!ops.empty() && hasPrecedence(tokens[i],ops.top())) { 
        ll val1 = values.top();
        values.pop();
        ll val2 = values.top();
        values.pop();
        ll val = appply(ops.top(),val1,val2);
        ops.pop();
        values.push(val);
      }
      ops.push(tokens[i]);
    }
  }
  while (!ops.empty()) {
    ll val1 = values.top();
    values.pop();
    ll val2 = values.top();
    values.pop();
    ll val = appply(ops.top(),val1,val2);
    ops.pop();
    values.push(val);
  }
  return values.top();
}


int main () {
  int t, k = 1;
  scanf("%d",&t);

  while (t--) {
    string str;
    cin >> str;
    vector <string> tokens = tokenize(str);
    // for (int i = 0; i < tokens.size(); i++) {
    //   printf("%s\n",tokens[i].c_str());
    // }
    // exit(0);
    int ans = evaluate(tokens);
    printf("Case #%d: %d\n",k++,ans);
  }
}