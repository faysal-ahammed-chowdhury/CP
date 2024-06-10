#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, k, a[N], b[N];

bool ok(int x) {
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    int need = x - a[i];
    cnt += upper_bound(b + 1, b + 1 + n, need) - b - 1;
  }
  return cnt >= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);

  int l = 0, r = 2e9, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
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