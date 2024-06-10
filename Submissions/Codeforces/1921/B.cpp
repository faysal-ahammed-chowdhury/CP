#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s, f; cin >> s >> f;
  int cnt1 = 0, cnt2 = 0;

  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (f[i] == '1' and s[i] != f[i]) {
      diff++;
    }
    if (s[i] != f[i]) {
      if (s[i] == '1') cnt1++;
      if (f[i] == '1') cnt2++;
    }
  }

  int ans = diff;
  if (cnt1 > cnt2) {
    ans += cnt1 - cnt2;
  }
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