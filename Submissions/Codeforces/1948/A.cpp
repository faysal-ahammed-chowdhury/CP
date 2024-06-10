#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i + i < n; i++) {
    cout << char(i + 'A') << char(i + 'A');
  }
  cout << '\n';
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