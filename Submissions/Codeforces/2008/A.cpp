#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b; cin >> a >> b;
  if (a & 1) {
    cout << "NO\n";
    return;
  }
  if (b % 2 == 0) {
    cout << "YES\n";
    return;
  }
  if ((b & 1) and a > 0) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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