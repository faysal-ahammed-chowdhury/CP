#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n; cin >> n;
  int a[n + 1];
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= n - 2) {
      sum += a[i];
    }
  }
  int ans = (a[n - 1] - sum);
  ans = a[n] - ans;
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