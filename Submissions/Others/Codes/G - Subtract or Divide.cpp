#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (n == 2) {
    cout << 1 << '\n';
    return;
  }
  if (n == 3) {
    cout << 2 << '\n';
    return;
  }
  if (n % 2 == 0) {
    cout << 2 << '\n';
    return;
  }
  cout << 3 << '\n';
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