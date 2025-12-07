#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int ans = 0, last1 = n + 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      last1 = i;
      continue;
    }
    if (last1 != n + 1 and i - last1 <= k) continue;
    if (s[i] == '0') ans++;
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