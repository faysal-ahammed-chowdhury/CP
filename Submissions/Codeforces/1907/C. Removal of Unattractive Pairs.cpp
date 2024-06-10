#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  int mx = 0;
  for (auto [_, cnt] : mp) {
    mx = max(mx, cnt);
  }
  int other = n - mx;
  int ans = 0;
  if (mx > other) {
    ans += mx - other;
  }
  else if (n & 1) ans++;
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