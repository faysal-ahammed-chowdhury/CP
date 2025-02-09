#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int ans = 0;
  for (auto c : s) {
    ans += c == '1';
  }
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