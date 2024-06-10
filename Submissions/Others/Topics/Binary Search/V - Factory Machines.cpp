#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, t, a[N];

bool ok(ll time) {
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (time / a[i]);
    if (cnt >= t) return true;
  }
  return cnt >= t;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll l = 1, r = 1e18, ans = -1;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}