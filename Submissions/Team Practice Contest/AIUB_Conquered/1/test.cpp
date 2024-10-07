#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int beauty(string &s) {
  int cnt = 0, ans = 0;
  for (auto c : s) {
    if (c == '(') cnt++;
    else if (cnt > 0) {
      cnt--;
      ans += 2;
    }
  }
  return ans;
}

void f(int i, string &s) {
  if (i > n) {
    ans = min(ans, beauty(s));
    if (beauty(s) == 10)cout << s << '\n';
    return;
  }
  if (s[i] == '?') {
    s[i] = '(';
    f(i + 1, s);
    s[i] = '?';
    s[i] = ')';
    f(i + 1, s);
    s[i] = '?';
  }
  else {
    f(i + 1, s);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  ans = 1e9;
  f(1, s);
  cout << ans << '\n';

  return 0;
}