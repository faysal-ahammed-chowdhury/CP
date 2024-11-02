#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 9;
const ll inf = 1e18 + 100;
int a[N], n;
ll k;

bool ok(ll x) {
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    int l = i + 1, r = n, ans = i;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (1ll * a[i] * a[mid] <= x) {
        // cout << "Here 1: " << mid << ' ' << a[i] * a[mid] << '\n';
        ans = mid;
        if (a[i] < 0) r = mid - 1;
        else l = mid + 1;
      }
      else {
        // cout << "Here 2: " << mid << ' ' << a[i] * a[mid] << '\n';
        if (a[i] < 0) l = mid + 1;
        else r = mid - 1;
      }
    }
    cnt += (a[i] < 0 ? (ans == i ? 0 : n - ans + 1) : ans - i);
    // cout << a[i] << ' ' << cnt << '\n';
  }
  // cout << cnt << '\n';
  return cnt < k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll l = -inf, r = inf, ans = inf + 10;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ++ans << '\n';
  // cout << ok(-7) << '\n';

  return 0;
}