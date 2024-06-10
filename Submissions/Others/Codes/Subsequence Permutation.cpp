#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) continue;
    ans++;
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