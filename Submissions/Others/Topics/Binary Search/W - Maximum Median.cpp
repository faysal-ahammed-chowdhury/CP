#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, k, a[N];

bool ok(int x) {
  int mid = n / 2 + 1;
  ll op = 0;
  for (int i = mid; i <= n; i++) {
    if (a[i] < x) {
      op += x - a[i];
    }
  }
  return op <= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + 1 + n);

  int l = 0, r = 2e9, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}