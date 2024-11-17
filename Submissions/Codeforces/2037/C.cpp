#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n <= 4) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i += 2) {
    if (i == 5) continue;
    cout << i << ' ';
  }
  cout << "5 4 ";
  for (int i = 2; i <= n; i += 2) {
    if (i == 4) continue;
    cout << i << ' ';
  }
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