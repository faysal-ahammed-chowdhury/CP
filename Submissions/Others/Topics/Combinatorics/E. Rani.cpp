#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int g = 0;
  for (int i = 1; i < n; i++) {
    g = __gcd(g, abs(a[i + 1] - a[i]));
  }
  int ans = abs(a[n] - a[1]) / g;
  --ans;
  for (int i = 2; i < n; i++) {
    if ((a[i] - a[1]) % g == 0) {
      ans--;
    }
  }
  cout << ans << '\n';

  return 0;
}