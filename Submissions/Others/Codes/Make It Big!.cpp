#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  ll ans = stol(s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (k == l) continue;
          swap(s[i], s[j]);
          swap(s[k], s[l]);
          ans = max(ans, ll(stol(s)));
          swap(s[k], s[l]);
          swap(s[i], s[j]);
        }
      }
    }
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