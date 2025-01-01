#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  bool all_dot = true;
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    all_dot &= s[i] == '.';
    if (s[i] == 'p' and idx == -1) {
      idx = i;
    }
  }

  if (all_dot) {
    cout << "YES\n";
    return;
  }

  if (idx != -1) {
    for (int i = idx + 1; i <= n; i++) {
      if (s[i] == 's') {
        cout << "NO\n";
        return;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] != 's') continue;
    for (int j = i + 1; j <= n; j++) {
      if (s[j] != 'p') continue;
      int d = j - i + 1;
      int d1 = j, d2 = n - i + 1;
      if (d < d1 and d < d2) {
        // cout << i << ' ' << j << ' ' << d << ' ' << d1 << ' ' << d2 << '\n';
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}