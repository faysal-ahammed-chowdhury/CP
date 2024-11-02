#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1], psum[n + 1];
  psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }
  map<int, int> mp;
  int ans = (n * (n + 1)) / 2;
  for (int i = 1; i <= n; i++) {
    int up = psum[i - 1] + x;
    int idx = upper_bound(psum + 1, psum + n + 1, up) - psum;
    if (idx > n) continue;
    // cout << i << ' ' << idx << '\n';
    mp[i]++;
    ans -= mp[i];
    mp[idx + 1] += mp[i];
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