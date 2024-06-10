#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int now = 1;
  int ans = 0;
  for (auto c : s) {
    int x = c - '0';
    if (x == 0) x = 10;
    if (x == now) ans++;
    else {
      ans += abs(x - now);
      ans++;
      now = x;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}