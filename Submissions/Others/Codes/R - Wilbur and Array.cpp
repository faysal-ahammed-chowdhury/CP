#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  int val = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - val);
    val = a[i];
  }

  cout << ans << '\n';

  return 0;
}