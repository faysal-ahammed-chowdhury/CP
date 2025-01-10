#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
    return;
  }

  string t = s.substr(idx);
  int m = t.size();
  t = '.' + t;

  string ans = "";
  int st = -1;
  for (int i = 1; i + m - 1 <= n; i++) {
    string here = "";
    for (int j = 1; j <= m; j++) {
      if (s[i + j - 1] == t[j]) here += '0';
      else here += '1';
    }
    if (ans <= here) {
      ans = here;
      st = i;
    }
  }

  cout << 1 << ' ' << n << ' ' << st << ' ' << st + m  - 1 << '\n';
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