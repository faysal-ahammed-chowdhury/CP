#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, n; cin >> a >> b >> n;
  int x[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x + 1, x + 1 + n);
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (b - 1);
    b = 1;
    b += x[i];
    b = min(b, a);
  }
  ans += b;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}