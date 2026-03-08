#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], pref[n + 1], suff[n + 2];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + abs(a[i]);
    pref[1] = a[1];
  }
  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + -(a[i]);
  }

  int ans = -1e18;
  for (int i = 1; i <= n; i++) {
    int cur = pref[i - 1] + suff[i + 1];
    // cout << i << ' ' << cur << '\n';
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}