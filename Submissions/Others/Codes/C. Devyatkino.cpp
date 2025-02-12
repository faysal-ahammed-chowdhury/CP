#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int n) {
  while (n > 0) {
    if (n % 10 == 7) return true;
    n /= 10;
  }
  return false;
}

void solve() {
  int n; cin >> n;
  int x = 9, ans = 100;
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j <= 9; j++) {
      if (ok(n + (x * j))) ans = min(ans, j);
    }
    x = x * 10 + 9;
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