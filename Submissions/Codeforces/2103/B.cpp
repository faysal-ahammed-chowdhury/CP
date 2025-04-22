#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  string t = ".";
  for (int i = 1; i <= n; i++) {
    if (t.back() != s[i]) {
      t += s[i];
    }
  }
  int m = t.size() - 1;
  // cout << "here: " << t << '\n';

  if (s[1] == '0') {
    if (m == 1) {
      cout << n << '\n';
      return;
    }
    if (m <= 3) {
      cout << n + 1 << '\n';
      return;
    }
    cout << n + m - 3 << '\n';
    return;
  }

  if (m <= 2) {
    int ans = n;
    cout << ++ans << '\n';
    return;
  }
  cout << n + m - 2 << '\n';
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