#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  ll a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  ll gc = 0;
  for (int i = 2; i <= n; i++) {
    gc = __gcd(gc, abs(a[i] - a[i - 1]));
  }
  for (int j = 1; j <= m; j++) {
    cout << __gcd(gc, a[1] + b[j]) << ' ';
  }
  cout << '\n';

  return 0;
}