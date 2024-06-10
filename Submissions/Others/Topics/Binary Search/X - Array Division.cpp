#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, k, a[N];

bool ok(ll max_sum) {
  for (int i = 1; i <= n; i++) {
    if (a[i] > max_sum) return false;
  }
  int subarray_cnt = 1; ll current_sum = a[1];
  for (int i = 2; i <= n; i++) {
    if (current_sum + a[i] <= max_sum) {
      current_sum += a[i];
    }
    else {
      subarray_cnt++;
      current_sum = a[i];
    }
  }
  return subarray_cnt <= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll l = 0, r = 2e14, ans = -1;
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