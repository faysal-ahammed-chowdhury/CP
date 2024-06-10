#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  ll sum = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    sum += pref[i + k - 1] - pref[i - 1];
  }

  double ans = (double)sum / (n - k + 1);

  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}