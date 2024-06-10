#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = 'x' + s;
  int start = -1, end = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') {
      start = i; break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'B') {
      end = i; break;
    }
  }

  int ans = max(0, end - start);
  if (start == -1) ans = 0;
  if (end == -1) ans = 0;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}