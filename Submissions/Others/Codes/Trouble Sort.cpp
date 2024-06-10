#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  bool all_one = true, all_zero = true;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    all_one &= x == 1;
    all_zero &= x == 0;
  }

  if (all_one or all_zero) {
    if (is_sorted(a + 1, a + n + 1)) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
    return;
  }

  cout << "Yes\n";
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