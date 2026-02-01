#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t; cin >> n >> t;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];

  int last_open = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > last_open) {
      int x = a[i] - last_open;
      ans += x;
      last_open = a[i] + 100;
    }
  }

  if (t >= last_open) {
    int x = t - last_open;
    ans += x;
  }

  cout << ans << '\n';

  return 0;
}