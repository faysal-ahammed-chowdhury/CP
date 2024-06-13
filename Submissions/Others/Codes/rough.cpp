#include <bits/stdc++.h>
using namespace std;

string s;
int n, cnt;

void f(int i, string str) {
  if (i == n) {
    if (str == "codeforces") cnt++;
    return;
  }
  f(i + 1, str);
  f(i + 1, str + s[i]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  s = "cccooddeeffoorrcceess";
  n = s.size();
  f(0, "");
  cout << cnt << '\n';

  return 0;
}