#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if (n == 1) {
    cout << a[1] << '\n';
    return;
  }

  ll ans = a[n] + a[n - 1] - 1;
  for (int i = n - 2; i >= 1; i--) {
    ans = ans + a[i] - 1;
  }
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