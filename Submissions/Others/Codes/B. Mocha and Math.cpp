#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int nd; cin >> nd;
  for (int i = 2; i <= n; i++) {
    int x; cin >> x;
    nd &= x;
  }
  cout << nd << '\n';
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