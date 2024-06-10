#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if (a[n] - a[1] < k) {
    cout << 1 << '\n';
    return 0;
  }
  int l = 2, r = n - 1, ans = 2;
  int last_left = a[1], last_right = a[n];
  while (l < r) {
    if (abs(a[l] - last_left) >= k and abs(a[l] - last_right) >= k) {
      last_left = a[l];
      ans++;
    }
    if (abs(a[r] - last_left) >= k and abs(a[r] - last_right) >= k) {
      last_right = a[r];
      ans++;
    }
    l++, r--;
  }

  if (l == r) {
    if (abs(a[r] - last_left) >= k and abs(a[r] - last_right) >= k) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}