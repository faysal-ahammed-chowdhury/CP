#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
const int N = 1e5 + 9;
const ll inf = 1e18;
int n, q;
ll a[N];

bool ok(ll x, ll k) {
  int idx = upper_bound(a + 1, a + n + 1, x) - &a[1];
  return (x - idx) >= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  while (q--) {
    ll k; cin >> k;
    ll l = 0, r = inf + N, ans = -1;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      // cout << mid << '\n';
      if (ok(mid, k)) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}