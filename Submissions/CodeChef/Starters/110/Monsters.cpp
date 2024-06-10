#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  if (n == 2) return true;
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int h; cin >> h;
  for (int i = 0; i <= 31; i++) {
    int x = (1 << i) - 1;
    int target = h - x;
    if (target == 0) {
      cout << i << '\n';
      return;
    }
    if (target > 0 and is_prime(target)) {
      cout << i + 1 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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