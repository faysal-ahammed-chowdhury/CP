#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  long long ans = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - last);
    last = a[i];
  }

  cout << ans << '\n';

  return 0;
}