#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;

bool ok(int len) {
  int per = m / (len + 1);
  ll possible = ((1ll * len * per) + (m % (len + 1))) * n;
  // cout << possible << '\n';
  return possible >= k;
}

void solve() {
  cin >> n >> m >> k;

  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  cout << ans << '\n';
  // cout << ok(2) << '\n';
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