#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n;

bool ok(int x) {
  return 1ll * x * x + x <= 2 * n;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int l = 1, r = 1e8, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  ll last_sum = (1ll * ans * (ans + 1)) / 2;
  cout << (n == last_sum ? ans : n - last_sum) << '\n';

  return 0;
}