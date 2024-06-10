#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> ans;

bool ischar(char c) {
  if (c >= 'a' and c <= 'z') return true;
  return (c >= 'A' and c <= 'Z');
}

void fun(int i, string &x) {
  if (i == n) {
    ans.push_back(x);
    return;
  }
  if (ischar(s[i])) {
    x[i] = tolower(s[i]);
    fun(i + 1, x);
    x[i] = toupper(s[i]);
    fun(i + 1, x);
  }
  else {
    x[i] = s[i];
    fun(i + 1, x);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();

  string x;
  x.resize(n, 'x');

  fun(0, x);

  for (auto x : ans) {
    cout << x << ' ';
  } 
  cout << '\n';

  return 0;
}