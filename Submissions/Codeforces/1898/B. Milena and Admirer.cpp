#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n +  1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  int last = a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] > a[i + 1]) {
      int here = (a[i] + a[i + 1] - 1) / a[i + 1];
      ans += here - 1;
      a[i] /= here; 
      cout << here << '\n';
      cout << a[i] << '\n';
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}