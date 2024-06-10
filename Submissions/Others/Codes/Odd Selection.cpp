#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int odd = 0, even = 0;
  for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    if (val & 1) odd++;
    else even++;
  }

  for (int i = 1; i <= odd and i <= x; i += 2) {
    int need = x - i;
    if (even >= need) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
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