#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  int freq[n + 1];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (freq[i] == 0) ans++;
  }

  ans = max(ans, freq[k]);

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