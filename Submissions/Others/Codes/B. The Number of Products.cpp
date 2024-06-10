#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  a[0] = 1;
  int pos = 0, neg = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) a[i] = -1;
    else a[i] = 1;
    a[i] *= a[i - 1];
    if (a[i] > 0) pos++;
    else neg++;
  }

  long long ans = (1ll * pos * neg) + neg;
  long long tot = (1ll * n * (n + 1)) / 2;
  cout << ans << ' ' << tot - ans << '\n';

  return 0;
}