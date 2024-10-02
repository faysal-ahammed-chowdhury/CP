#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  vector<int> v;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i] / k;
    v.push_back(k - (a[i] % k));
  }
  int m; cin >> m;
  sort(v.begin(), v.end());
  for (auto x : v) {
    if (x == 0) continue;
    if (m >= x) {
      ans++;
      m -= x;
    }
  }
  ans += m / k;
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