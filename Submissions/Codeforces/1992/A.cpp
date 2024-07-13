#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a[4]; cin >> a[1] >> a[2] >> a[3];
  for (int i = 1; i <= 5; i++) {
    sort(a + 1, a + 3 + 1);
    a[1]++;
  }
  int ans = a[1] * a[2] * a[3];
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}