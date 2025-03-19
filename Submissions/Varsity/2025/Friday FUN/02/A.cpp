#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  bool all_one = true;

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_one &= a[i] == 1;
    cnt += a[i] == 1;
  }

  if (all_one) {
    cout << 0 << '\n';
    return 0;
  }

  if (cnt > 0) {
    cout << n - cnt << '\n';
    return 0;
  }

  int d = 1e9;
  for (int i = 1; i <= n; i++) {
    int gc = a[i];
    for (int j = i; j <= n; j++) {
      gc = __gcd(gc, a[j]);
      if (gc == 1) {
        d = min(d, j - i);
      }
    }
  }

  if (d == 1e9) {
    cout << -1 << '\n';
    return 0;
  }

  cout << d + n - 1  << '\n';

  return 0;
}