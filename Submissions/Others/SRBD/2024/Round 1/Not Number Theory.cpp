#include <bits/stdc++.h>
using namespace std;

int n;
int cnt, ans;

void f(int i, string &s) {
  if (i == n) {
    int x = stoi(s);
    bitset<20> bs(x);
    int y = __builtin_popcount(x);
    if (y >= cnt) {
      cnt = y;
      ans = max(ans, x);
    }
    return;
  }
  if (s[i] == '?') {
    for (int j = 0; j < 10; j++) {
      s[i] = '0' + j; 
      f(i + 1, s);
      s[i] = '?';
    }
  }
  else {
    f(i + 1, s);
  }
}

void solve() {
  string s; cin >> s;
  n = s.size();
  cnt = 0;
  ans = 0;
  f(0, s);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}