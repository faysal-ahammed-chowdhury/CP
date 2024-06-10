#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, d; cin >> n >> d;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[i - 1]) {
      ll diff = a[i - 1] - a[i] + 1;
      ll cnt = (diff + d - 1) / d;
      ans += cnt;
      a[i] += cnt * d;
    }
  }

  cout << ans << '\n';

  return 0;
}